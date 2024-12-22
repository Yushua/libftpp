#ifndef THREAD_HPP
#define THREAD_HPP

#include <thread>
#include <string>
#include <functional>

class Thread {
public:
    Thread(const std::string& name, std::function<void()> functToExecute);
    void start();
    void stop();

private:
    std::string name_;
    std::function<void()> functToExecute_;
    std::thread thread_;
};

#endif