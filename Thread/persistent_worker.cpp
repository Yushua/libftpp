#include "persistent_worker.hpp"

PersistentWorker::PersistentWorker() : stopFlag(false) {
    workerThread = std::thread([this]() { this->run(); });
}

PersistentWorker::~PersistentWorker() {
    {
        std::unique_lock<std::mutex> lock(taskMutex);
        stopFlag = true;
    }
    taskCondition.notify_all();
    if (workerThread.joinable()) {
        workerThread.join();
    }
}

void PersistentWorker::addTask(const std::string& name, const std::function<void()>& jobToExecute) {
    {
        std::unique_lock<std::mutex> lock(taskMutex);
        tasks[name] = jobToExecute;
    }
    taskCondition.notify_all();
}

void PersistentWorker::removeTask(const std::string& name) {
    {
        std::unique_lock<std::mutex> lock(taskMutex);
        tasks.erase(name);
    }
    taskCondition.notify_all();
}

void PersistentWorker::run() {
    while (true) {
        std::unordered_map<std::string, std::function<void()>> currentTasks;
        {
            std::unique_lock<std::mutex> lock(taskMutex);
            if (stopFlag) {
                return;
            }
            currentTasks = tasks;
        }
        for (const auto& task : currentTasks) {
            task.second();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
