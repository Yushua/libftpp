#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <functional>
#include <unordered_map>
#include <vector>
#include <type_traits>

template <typename TEvent>
class Observer {
    static_assert(std::is_enum<TEvent>::value, "TEvent must be an enum type.");

public:
    // Subscribe a lambda to a specific event
    void subscribe(const TEvent& event, const std::function<void()>& lambda) {
        observers[static_cast<int>(event)].push_back(lambda);
    }

    // Notify all lambdas subscribed to the event
    void notify(const TEvent& event) {
        int eventKey = static_cast<int>(event);
        if (observers.find(eventKey) != observers.end()) {
            for (const auto& callback : observers[eventKey]) {
                callback();
            }
        }
    }

private:
    std::unordered_map<int, std::vector<std::function<void()>>> observers;
};

#endif
