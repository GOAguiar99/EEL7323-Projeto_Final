/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 26/11/2022
 * File: UART.hpp
*/
 
#ifndef UART_H
#define UART_H

/* UART Buffer Defines */
#define UART_RX_BUFFER_SIZE 256     /* 2,4,8,16,32,64,128 or 256 bytes */
#define UART_TX_BUFFER_SIZE 256     /* 2,4,8,16,32,64,128 or 256 bytes */
#define UART_RX_BUFFER_MASK (UART_RX_BUFFER_SIZE - 1)
#define UART_TX_BUFFER_MASK (UART_TX_BUFFER_SIZE - 1) 

class UART
{
	private:
		int serial_port;
	
	public:
		UART_Init();
		UART_Write(unsigned char* tx_buffer, size_t size);
		UART_Read(unsigned char* rx_buffer);
		UART_Close();
}
