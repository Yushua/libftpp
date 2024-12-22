#ifndef PERSISTENT_WORKER_HPP
#define PERSISTENT_WORKER_HPP

#include <thread>
#include <unordered_map>
#include <functional>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <string>

class PersistentWorker {
public:
    PersistentWorker();
    ~PersistentWorker();

    void addTask(const std::string& name, const std::function<void()>& jobToExecute);
    void removeTask(const std::string& name);

private:
    void run();

    std::unordered_map<std::string, std::function<void()>> tasks;
    std::thread workerThread;
    std::mutex taskMutex;
    std::condition_variable taskCondition;
    std::atomic<bool> stopFlag;
};

#endif
