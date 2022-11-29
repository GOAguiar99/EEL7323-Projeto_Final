#include "RaspberryPi.hpp"

RaspberryPi::RaspberryPi()
    : m_SystemTimerMemory(m_PhysicalMemory.GetHandle(), SYSTEM_TIMER_BASE, SYSTEM_TIMER_SIZE),
      m_SystemTimer(m_SystemTimerMemory.GetHandle()),
      m_GpioMemory(m_PhysicalMemory.GetHandle(), GPIO_BASE, GPIO_SIZE),
      m_Gpio(m_GpioMemory.GetHandle())
{
}

RaspberryPi::~RaspberryPi()
{
}

SystemTimer& RaspberryPi::SystemTimer()
{
    return m_SystemTimer;
}

Gpio& RaspberryPi::Gpio()
{
    return m_Gpio;
}
