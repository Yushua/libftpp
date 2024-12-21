#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <memory>
#include <stdexcept>

template <typename TType>
class Singleton {
public:
    // Returns the managed instance of TType
    static TType* instance() {
        if (!managedInstance) {
            throw std::runtime_error("Instance not created. Call instantiate() first.");
        }
        return managedInstance.get();
    }

    // Sets up the managed instance of the class
    template <typename... TArgs>
    static void instantiate(TArgs&&... args) {
        if (managedInstance) {
            throw std::runtime_error("Instance already created.");
        }
        managedInstance = std::make_unique<TType>(std::forward<TArgs>(args)...);
    }

protected:
    Singleton() = default;
    ~Singleton() = default;

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    static inline std::unique_ptr<TType> managedInstance = nullptr;
};

#endif
