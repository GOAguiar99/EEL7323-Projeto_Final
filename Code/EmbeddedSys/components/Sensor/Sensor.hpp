/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 26/11/2022
 * File: Sensor.hpp
 */
 
#ifndef _SENSOR_HPP_
#define _SENSOR_HPP_

class Sensor {
	    int sensor_ID;
	protected:
		int getID();
		void setID(int);
		virtual void readSensor() = 0;		// pure virtual function
};

#endif /* _SENSOR_HPP_ */
