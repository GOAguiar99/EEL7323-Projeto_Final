#pragma once

#include <cstdint>

/*
 * This class provides access to the genereral purpose I/O ports (GPIO).
 */
class Gpio
{

public:
    /*
     * Constructor
     * Provide the base memory address as parameter.
     */
    explicit Gpio(void* Base);

    /*
     * Configure the GPIO pin as input pin.
     */
    void SetInput(int Pin);

    /*
     * Configure the GPIO pin as output pin.
     */
    void SetOutput(int Pin);

    /*
     * Set voltage on the GPIO pin. Pin should be configured as output pin.
     */
    void SetHigh(int Pin);

    /*
     * Clear voltage on the GPIO pin. Pin should be configured as output pin.
     */
    void SetLow(int Pin);

    /*
     * Set or clear the volage on the GPIO pin depending on the parameter.
     */
    void Set(int Pin, bool High);

    /*
     * Check if there is voltage at the GPIO pin. Pin should be configured as input pin.
     */
    bool IsHigh(int Pin) const;

    /*
     * Check if there is no voltage at the GPIO pin. Pin should be configured as input pin.
     */
    bool IsLow(int Pin) const;

private:
    volatile uint32_t* m_Register; /* base address */

    volatile uint32_t* m_FunctionSelect; /* configure pins as input or output pins */
    volatile uint32_t* m_PinOutputSet; /* set output pin high */
    volatile uint32_t* m_PinOutputClear; /* set output pin low */
    volatile uint32_t* m_PinLevel; /* check if input pin is high */

};
