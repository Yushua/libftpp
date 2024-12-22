#include "thread_safe_iostream.hpp"

// Define static members
std::mutex ThreadSafeIOStream::ioMutex;
thread_local std::string ThreadSafeIOStream::threadPrefix = "";

// Define the global instance
thread_local ThreadSafeIOStream threadSafeCout(std::cout);

// Constructor
ThreadSafeIOStream::ThreadSafeIOStream(std::ostream& stream) : outStream(stream) {}

// Overload for the manipulator
ThreadSafeIOStream& ThreadSafeIOStream::operator<<(std::ostream& (*manip)(std::ostream&)) {
    std::lock_guard<std::mutex> lock(ioMutex);
    outStream << manip;
    return *this;
}
