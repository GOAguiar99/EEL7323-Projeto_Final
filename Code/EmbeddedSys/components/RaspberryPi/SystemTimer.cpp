#include "SystemTimer.hpp"

SystemTimer::SystemTimer(void* Base)
    : m_Register(reinterpret_cast<uint32_t*>(Base)),
      m_Counter(m_Register + 1)
{

}

uint32_t SystemTimer::GetTicks() const
{
    return *m_Counter;
}

uint32_t SystemTimer::GetFrequency() const
{
    return 1000000;
}
