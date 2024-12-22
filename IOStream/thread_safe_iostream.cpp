#include "../includes/libftpp.hpp" 

std::mutex ThreadSafeIOStream::ioMutex;
thread_local std::string ThreadSafeIOStream::threadPrefix = "";

thread_local ThreadSafeIOStream threadSafeCout(std::cout);

ThreadSafeIOStream::ThreadSafeIOStream(std::ostream& stream) : outStream(stream) {}

ThreadSafeIOStream& ThreadSafeIOStream::operator<<(std::ostream& (*manip)(std::ostream&)) {
    std::lock_guard<std::mutex> lock(ioMutex);
    outStream << manip;
    return *this;
}
