#include "Gpio.hpp"

#include <stdexcept>

Gpio::Gpio(void* Base)
    : m_Register(reinterpret_cast<uint32_t*>(Base)),
      m_FunctionSelect(m_Register),
      m_PinOutputSet(m_Register + 7),
      m_PinOutputClear(m_Register + 10),
      m_PinLevel(m_Register + 13)
{
}

void Gpio::SetInput(int Pin)
{
    int RegisterIndex = Pin / 10;
    int BitOffset = (Pin % 10) * 3;
    m_FunctionSelect[RegisterIndex] &= ~(0x7 << BitOffset);
}

void Gpio::SetOutput(int Pin)
{
    int RegisterIndex = Pin / 10;
    int BitOffset = (Pin % 10) * 3;
    m_FunctionSelect[RegisterIndex] = (m_FunctionSelect[RegisterIndex] & ~(0x7 << BitOffset)) | (0x1 << BitOffset);
}

void Gpio::SetHigh(int Pin)
{
    int RegisterIndex = Pin / 32;
    int BitOffset = Pin % 32;
    m_PinOutputSet[RegisterIndex] = (0x1 << BitOffset);
}

void Gpio::SetLow(int Pin)
{
    int RegisterIndex = Pin / 32;
    int BitOffset = Pin % 32;
    m_PinOutputClear[RegisterIndex] = (0x1 << BitOffset);
}

void Gpio::Set(int Pin, bool High)
{
    if (High)
    {
        SetHigh(Pin);
    }
    else
    {
        SetLow(Pin);
    }
}

bool Gpio::IsHigh(int Pin) const
{
    int RegisterIndex = Pin / 32;
    int BitOffset = Pin % 32;
    return m_PinLevel[RegisterIndex] & (0x1 << BitOffset);
}

bool Gpio::IsLow(int Pin) const
{
    return !IsHigh(Pin);
}

