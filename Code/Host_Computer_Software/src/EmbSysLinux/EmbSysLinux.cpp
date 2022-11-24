/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 23/11/2022
 * File: EmbSysLinux.cpp
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <iostream>
#include <string.h>
#include <sys/ioctl.h>
#include "EmbSysLinux.h"


void EmbSysLinux::openSerial(const char* port){

   struct termios options;


   serial = open(port, O_RDWR|O_NOCTTY|O_NDELAY);
   if (serial == -1)      // ERROR!!
        std::cout << "Error opening " << serial << std::endl;
   else
        fcntl(serial, F_SETFL, 0);
   std::cout << "Serial port in use: " << port << std::endl << std::endl;

   // Program serial port to 115200, 8, 1, no parity
   //

   // Get the current options for the port
   tcgetattr(serial, &options);

   // Set the baud rate to 115200
   cfsetispeed(&options, B115200);
   cfsetospeed(&options, B115200);

   // Enable the receiver and set local mode
   options.c_cflag |= (CLOCAL | CREAD);

   // Setting parity checking (no parity) 8N1
   options.c_cflag &= ~PARENB;        /* no parity */
   options.c_cflag &= ~CSTOPB;        /* 1 stop bit */
   options.c_cflag &= ~CSIZE;         /* Mask the character size bits */
   options.c_cflag |= CS8;            /* Select 8 data bits */

   // Setting raw input
   options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

   // Setting raw output
   options.c_oflag &= ~OPOST;

   // Set the new options for the port
   tcsetattr(serial, TCSANOW, &options);

}


uint8_t EmbSysLinux::sendCommand(uint8_t cmd){

    uint8_t npkg=-1;                                                           // Number of packets to receive from the embedded system

    if (serial == -1)
        std::cout << "Erro: the serial port is closed. Please, "
        << "use the openSerial() method to open it. " << std::endl;
    else{
        int n = write(serial, &cmd, 1);  // send 2 bytes command
        if (n < 0)
            std::cout << "Error! write() command failed." << std::endl;
        else {
            fcntl(serial, F_SETFL, FNDELAY);
            int i = read(serial, &npkg, 1); // read 1 Byte interface status
            fcntl(serial, F_SETFL, 0);
        }
    }
    return npkg;
}

void EmbSysLinux::serialMonitor(){
    int i, nbytes;

    Datapkt data;
    

    if (serial == -1)
        std::cout << "Erro: the serial port is closed. Please, "
        << "use the openSerial() method to open it. " << std::endl;
    else
    {
        data.val1 = 1;
        data.val2 = 1;
        data.id = 1;
        data.pktn = 1;
        while(true)
        {                                                                   // Read incoming data routine (depends on definition of Node, expected to read data in hex format)
            ioctl(serial, FIONREAD, &nbytes);
            if (nbytes > 0)                                                 // Detect bytes in IO buffer
            {
                i = read(serial, data.msg, nbytes);                         // Read available log (for now, a simple Hello World!)
                log.enqueue(data);                                          // Store log
                data.pktn++;
            }
            usleep(100000);                                                 // Wait before trying to read again
        }
    }
}
