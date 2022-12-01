/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 26/11/2022
 * File: UART.cpp
 */
 
#include <cstdio>
#inclde <cerrno>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include "UART.hpp"

static const char* UART_TAG = "UART_CPP";

UART::UART_Init()
{
  serial_port = open("/dev/ttyUSB0", O_RDWR);
  struct termios tty;

  /*Check for terminal parameter get errors*/ 
  if(tcgetattr(serial_port, &tty) != 0) {
  	cout << "Error "<< errno <<  "from tcgetattr: "<< strerror(errno) << endl;
      return 1;    
  }
  
  tty.c_cflag &= ~PARENB;
  tty.c_cflag &= ~CSTOPB;
  tty.c_cflag &= ~CSIZE;
  tty.c_cflag |= CS8;
  tty.c_cflag &= ~CRTSCTS;
  tty.c_cflag |= CREAD | CLOCAL;
  tty.c_lflag &= ~ICANON;
  tty.c_lflag &= ~ECHO;
  tty.c_lflag &= ~ECHOE;
  tty.c_lflag &= ~ECHONL;
  tty.c_lflag &= ~ISIG;
  tty.c_iflag &= ~(IXON | IXOFF | IXANY);
  tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL);
  tty.c_oflag &= ~OPOST;
  tty.c_oflag &= ~ONLCR;
  tty.c_cc[VTIME] = 10;
  tty.c_cc[VMIN] = 0;
  
  /*Set Baud Rate to 9600 bps*/
  cfsetispeed(&tty, B9600);
  cfsetospeed(&tty, B9600);
  
  /*Check for terminal parameter set errors*/ 
  if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
  	cout << "Error "<< errno <<  "from tcsetattr: "<< strerror(errno) << endl;
      return 1;
  }
}

UART::UART_Write(unsigned char* tx_buffer, size_t size)
{
	unsigned char *p_tx_buffer;
	
	p_tx_buffer = &tx_buffer[0];
	
	if (serial_port != -1)
	{
		int count = write(serial_port, &tx_buffer[0], (p_tx_buffer - &tx_buffer[0]));		//Serial port, bytes to write, number of bytes to write
		if (count < 0)
		{
			cout<<"UART TX error"<< endl;
		}
	}
}

int UART::UART_Read(unsigned char* rx_buffer)
{
	if (serial_port != -1)
	{
		// Read up to 255 characters from the port if they are there
		int rx_length = read(serial_port, (void*)rx_buffer, UART_RX_BUFFER_MASK);		//Filestream, buffer to store in, number of bytes to read (max)
		if (rx_length < 0)
		{
			//An error occured (will occur if there are no bytes)
			cout << "Error reading " <<  strerror(errno) << endl;
			
			return -1;
		}
		else if (rx_length == 0)
		{
			//No data waiting
			return 0;
		}
		else
		{
			//Bytes received
			rx_buffer[rx_length] = '\0';
			
			return 1;
		}
	}
}

UART::UART_Close()
{
	close(serial_port);
}
