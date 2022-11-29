#pragma once

#include <cstdint>

/* 
 * This class provides access to the Raspberry Pi system timer. This is a clock with 1 MHz resolution.
*/
class SystemTimer
{

public:
    /*
     * Constructor
     * Provide the physical memory address to the system timer as address.
     */
    explicit SystemTimer(void* Base);

    /*
     * Returns the current number of ticks of the system timer.
     */
    uint32_t GetTicks() const;

    /*
     * Returns the number of ticks per second the system timer provides.
     */
    uint32_t GetFrequency() const;

private:
    volatile uint32_t* m_Register; /* the base memory address */

    volatile uint32_t* m_Counter; /* the the lower 32 bit of the counter*/

}; // class SystemTimer
