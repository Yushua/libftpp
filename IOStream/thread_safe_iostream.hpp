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
    explicit ThreadSafeIOStream(std::ostream& stream = std::cout);

    void setPrefix(const std::string& prefix) {
        this->threadPrefix = prefix;
    }
    
    template<typename T>
    ThreadSafeIOStream& operator<<(const T& data) {
        std::lock_guard<std::mutex> lock(ioMutex);
        outStream << threadPrefix << data;
        return *this;
    }

    ThreadSafeIOStream& operator<<(std::ostream& (*manip)(std::ostream&));

    template<typename T>
    void prompt(const std::string& question, T& dest) {
        std::lock_guard<std::mutex> lock(ioMutex);
        outStream << threadPrefix << question;
        outStream.flush();
        std::cin >> dest;
    }
};

extern thread_local ThreadSafeIOStream threadSafeCout;

#endif
