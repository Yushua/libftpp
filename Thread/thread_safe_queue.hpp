#ifndef THREAD_SAFE_QUEUE_HPP
#define THREAD_SAFE_QUEUE_HPP

#include <deque>
#include <mutex>
#include <stdexcept>

template <typename TType>
class ThreadSafeQueue {
public:
    // Adds an element at the end of the queue.
    void push_back(const TType& newElement) {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push_back(newElement);
    }

    // Adds an element to the front of the queue.
    void push_front(const TType& newElement) {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push_front(newElement);
    }

    // Extracts the last element from the queue.
    TType pop_back() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (queue_.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        TType value = queue_.back();
        queue_.pop_back();
        return value;
    }

    // Extracts the first element from the queue.
    TType pop_front() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (queue_.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        TType value = queue_.front();
        queue_.pop_front();
        return value;
    }

private:
    std::deque<TType> queue_; // Underlying queue
    std::mutex mutex_; // Mutex to ensure thread safety
};

#endif