/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 26/11/2022
 * File: main.cpp
 */

#include <cstdio>
#include <iostream>
#include <string>

#include <wiringPi.h>
#include "UART.hpp"

using namespace std;

int main()
{
wiringPiSetup();			// Setup the library
UART_Init();

StationController Controler;
	
	while(1)
	{
		
		Controler.FSM(); //Control and change for the next estate

		Controler.checkLog(); //Check of event for create log
		Controler.sendLog(); //Send the log via UART Interrupt based
	}
}
