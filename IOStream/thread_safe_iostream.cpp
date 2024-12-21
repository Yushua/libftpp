#include "thread_safe_iostream.hpp"

// Define static members
std::mutex ThreadSafeIOStream::ioMutex;
thread_local std::string ThreadSafeIOStream::threadPrefix = "";

// Define the global instance
thread_local ThreadSafeIOStream threadSafeCout(std::cout);

// Constructor
ThreadSafeIOStream::ThreadSafeIOStream(std::ostream& stream) : outStream(stream) {}

// Set the prefix for the current thread
void ThreadSafeIOStream::setPrefix(const std::string& prefix) {
    threadPrefix = prefix;
}

// Template implementation for << operator
template<typename T>
ThreadSafeIOStream& ThreadSafeIOStream::operator<<(const T& data) {
    std::lock_guard<std::mutex> lock(ioMutex);
    outStream << threadPrefix << data;
    return *this;
}

// Overload for the manipulator (e.g., endl)
ThreadSafeIOStream& ThreadSafeIOStream::operator<<(std::ostream& (*manip)(std::ostream&)) {
    std::lock_guard<std::mutex> lock(ioMutex);
    outStream << manip;
    return *this;
}

// Template for prompting the user
template<typename T>
void ThreadSafeIOStream::prompt(const std::string& question, T& dest) {
    std::lock_guard<std::mutex> lock(ioMutex);
    outStream << threadPrefix << question;
    outStream.flush();
    std::cin >> dest;
}

// Explicit template instantiations for common types
template ThreadSafeIOStream& ThreadSafeIOStream::operator<<(const int& data);
template ThreadSafeIOStream& ThreadSafeIOStream::operator<<(const std::string& data);
template ThreadSafeIOStream& ThreadSafeIOStream::operator<<(const char* data);
template ThreadSafeIOStream& ThreadSafeIOStream::operator<<(const float& data);
template ThreadSafeIOStream& ThreadSafeIOStream::operator<<(const double& data);
template ThreadSafeIOStream& ThreadSafeIOStream::operator<<(const long& data);

// Explicit instantiation for other types
template ThreadSafeIOStream& ThreadSafeIOStream::operator<<(const char(&)[9]);  // For "char[9]" (string literals with 9 characters)
template ThreadSafeIOStream& ThreadSafeIOStream::operator<<(const int&);  // Just in case for int
