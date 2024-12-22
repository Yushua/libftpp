#include "thread.hpp"
#include "../includes/libftpp.hpp"

Thread::Thread(const std::string& name, std::function<void()> functToExecute)
    : name_(name), functToExecute_(functToExecute) {}

void Thread::start() {
    thread_ = std::thread([this]() {
        functToExecute_();
    });
}

void Thread::stop() {
    if (thread_.joinable()) {
        thread_.join();
    }
}