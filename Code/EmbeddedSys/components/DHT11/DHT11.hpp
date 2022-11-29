#pragma once

#include <cstdint>
#include "Sensor.hpp"

class RaspberryPi;
class SystemTimer;
class Gpio;

/*
 * This class provides an abstraction for a DHT11 sensor for measuring temperature and humidity.
 */
class DHT11 : public Sensor
{
public:
    /* This is the measurement data returned to the user */
	struct CData
	{
		int Temperature; /* in degrees celcius */
		int Humidity; /* humidity in percent */
	};

public:
    /*
     * Constructor
     * Provide an instance to a raspberry pi object and the GPIO pin for data transmission.
     */
    DHT11(RaspberryPi& RaspberryPi, int GpioPin);

    /*
     * This method starts a measurement and returns the data from the last measurement.
     * This behaviour is due to how the DHT11 sensor works. Make two consecutive readings
     * to get the most current data. But wait at least 5 seconds between measurements,
     * otherwise the data will be wrong.
     */
	CData Measure();

private:
    /*
     * Signal the sensor that we want to read the data.
     */
	void SendStartSignal();

    /*
     * Wait for the GPIO pin to get low. Returns the microseconds waited until the pin got low.
     */
	int WaitForLow();

    /*
     * Wait for the GPIO pin to get high. Returns the microseconds waited until the pin git high.
     */
    int WaitForHigh();

    /*
     * Extracts the relevant data from the binary raw data.
     */
	CData ProcessData(uint64_t Data);

    /*
     * Calculates the checksum for the data to make sure there was no error during data transmission.
     */
	uint8_t CalculateParity(uint8_t HumidityHigh, uint8_t HumidityLow, uint8_t TemperatureHigh, uint8_t TemperatureLow);

private:
	SystemTimer& m_SystemTimer;
	Gpio& m_Gpio;
	const int m_GpioPin;

};
