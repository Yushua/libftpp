#ifndef WORKER_POOL_HPP
#define WORKER_POOL_HPP

#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>

class WorkerPool {
public:
    WorkerPool(size_t numThreads);
    ~WorkerPool();
    void addJob(const std::function<void()>& jobToExecute);

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> jobs;
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stopFlag;
};

#endif