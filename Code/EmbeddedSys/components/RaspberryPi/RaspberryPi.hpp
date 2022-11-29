#pragma once

#include "PhysicalMemory.hpp"
#include "MemoryMapper.hpp"
#include "Gpio.hpp"
#include "SystemTimer.hpp"

/*
 * This class provides an abstraction for the Raspberry Pi. It returns objects for accessing its peripheral hardware.
 */
class RaspberryPi
{
public:
	
 	const std::size_t GPIO_OFFSET = 0x00200000; /* datasheet: 6.1 Register View (page 90) */
    const std::size_t GPIO_BASE = BCM2835_PERIPHERALS_BASE + GPIO_OFFSET;
    const std::size_t GPIO_SIZE = 41 * sizeof(uint32_t);

    const std::size_t SYSTEM_TIMER_OFFSET = 0x00003000; /* datasheet: 12 System Timer (page 172) */
    const std::size_t SYSTEM_TIMER_BASE = BCM2835_PERIPHERALS_BASE + SYSTEM_TIMER_OFFSET;
    const std::size_t SYSTEM_TIMER_SIZE = 7 * sizeof(uint32_t);
    
public:
    /*
     * Constructor
     * Initializes all components
     */
    RaspberryPi();

    /*
     * Destructor
     */
    ~RaspberryPi();

    /*
     * Returns the system timer object
     */
    SystemTimer& SystemTimer();

    /*
     * Returns the GPIO object
     */
    Gpio& Gpio();

private:
    PhysicalMemory m_PhysicalMemory;

    MemoryMapper m_SystemTimerMemory;
    SystemTimer m_SystemTimer;

    MemoryMapper m_GpioMemory;
    Gpio m_Gpio;

};
