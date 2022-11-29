/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 26/11/2022
 * File: Sensor.cpp
 */
#include <stdexcept>
#include <iostream>
#include <chrono>
#include <thread>

#include "RaspberryPi.hpp"
#include "DHT11.hpp"

#include "Sensor.hpp"

int Sensor::getID(){
	return sensor_ID;
}

void Sensor::setID(int newID){
	sensor_ID = newID;
}
