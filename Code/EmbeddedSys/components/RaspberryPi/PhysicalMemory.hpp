#pragma once

/*
 * This is a helper class for accessing physical memory.
 */
class PhysicalMemory
{

public:
    /*
     * Constructor
     * Opens physical memory as a file descriptor for reading and writing.
     */
    PhysicalMemory();

    /*
     * Destructor
     * Closes the file descriptor for the physical memory.
     */
    ~PhysicalMemory();

    /*
     * Returns the file handle for accessing the physical memory.
     */
    int GetHandle() const;

private:
    int m_Handle; /* file handle */

}; // class PhysicalMemory
