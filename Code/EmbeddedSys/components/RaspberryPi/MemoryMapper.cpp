#include "MemoryMapper.hpp"

#include <stdexcept>
#include <sys/mman.h>

MemoryMapper::MemoryMapper(int FileHandle, std::size_t Offset, std::size_t Size)
    : m_Size(Size)
{
    m_Handle = mmap(
        nullptr,
        m_Size,
        PROT_READ | PROT_WRITE,
        MAP_SHARED,
        FileHandle,
        Offset);
    if (m_Handle == MAP_FAILED)
    {
        throw std::runtime_error("Unable to map memory into process.");
    }
}

MemoryMapper::~MemoryMapper()
{
    munmap(m_Handle, m_Size);
}

void* MemoryMapper::GetHandle() const
{
    return m_Handle;
}
