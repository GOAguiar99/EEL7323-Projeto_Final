#include "PhysicalMemory.hpp"

#include <stdexcept>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

PhysicalMemory::PhysicalMemory()
{
    m_Handle = open("/dev/mem", O_RDWR | O_SYNC);
    if (m_Handle == -1)
    {
        throw std::runtime_error("Unable to open /dev/mem for read and write access. Check permissions.");
    }
}

PhysicalMemory::~PhysicalMemory()
{
    close(m_Handle);
}

int PhysicalMemory::GetHandle() const
{
    return m_Handle;
}
