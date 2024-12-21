#ifndef THREAD_SAFE_IOSTREAM_HPP
#define THREAD_SAFE_IOSTREAM_HPP

#include <iostream>
#include <mutex>
#include <string>
#include <thread>

class ThreadSafeIOStream {
private:
    std::ostream& outStream;
    static std::mutex ioMutex;
    thread_local static std::string threadPrefix;

public:
    ThreadSafeIOStream(std::ostream& stream = std::cout);

    void setPrefix(const std::string& prefix);

    template<typename T>
    ThreadSafeIOStream& operator<<(const T& data);

    ThreadSafeIOStream& operator<<(std::ostream& (*manip)(std::ostream&));

    template<typename T>
    void prompt(const std::string& question, T& dest);
};

// Declare the global thread-safe stream instance
extern thread_local ThreadSafeIOStream threadSafeCout;

// Template implementation for << operator
template<typename T>
ThreadSafeIOStream& ThreadSafeIOStream::operator<<(const T& data) {
    std::lock_guard<std::mutex> lock(ioMutex);
    outStream << threadPrefix << data;
    return *this;
}

// Overload for the manipulator (e.g., endl)
inline ThreadSafeIOStream& ThreadSafeIOStream::operator<<(std::ostream& (*manip)(std::ostream&)) {
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

#endif