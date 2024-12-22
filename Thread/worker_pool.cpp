#include "worker_pool.hpp"
#include <stdexcept>

WorkerPool::WorkerPool(size_t numThreads) : stopFlag(false) {
    for (size_t i = 0; i < numThreads; ++i) {
        workers.emplace_back([this]() {
            while (true) {
                std::function<void()> job;
                {
                    std::unique_lock<std::mutex> lock(this->queueMutex);
                    this->condition.wait(lock, [this]() { return this->stopFlag || !this->jobs.empty(); });
                    if (this->stopFlag && this->jobs.empty()) {
                        return;
                    }
                    job = std::move(this->jobs.front());
                    this->jobs.pop();
                }
                job();
            }
        });
    }
}

WorkerPool::~WorkerPool() {
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        stopFlag = true;
    }
    condition.notify_all();
    for (std::thread &worker : workers) {
        worker.join();
    }
}

void WorkerPool::addJob(const std::function<void()>& jobToExecute) {
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        if (stopFlag) {
            throw std::runtime_error("WorkerPool is stopping, cannot add new jobs");
        }
        jobs.push(jobToExecute);
    }
    condition.notify_one();
}