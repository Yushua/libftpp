#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

#include <functional>
#include <map>
#include <stdexcept>
#include <unordered_map>
#include <optional>

template<typename TState>
class StateMachine {
public:
    // Adds a new state to the state machine.
    void addState(const TState& state) {
        if (states.find(state) == states.end()) {
            states[state] = {};
        }
        if (!currentState.has_value()) {
            currentState = state; // Automatically set the first added state as the initial state
        }
    }

    // Adds a transition between two states with an associated lambda function.
    void addTransition(const TState& startState, const TState& finalState, const std::function<void()>& lambda) {
        if (states.find(startState) == states.end() || states.find(finalState) == states.end()) {
            throw std::invalid_argument("State not found.");
        }
        transitions[{startState, finalState}] = lambda;
    }

    // Adds an action to execute while in a specific state.
    void addAction(const TState& state, const std::function<void()>& lambda) {
        if (states.find(state) == states.end()) {
            throw std::invalid_argument("State not found.");
        }
        states[state].action = lambda;
    }

    // Transitions to a specified state, executing the associated transition lambda if it exists.
    void transitionTo(const TState& state) {
        if (states.find(state) == states.end()) {
            throw std::invalid_argument("State not found.");
        }

        if (currentState.has_value()) {
            auto transitionKey = std::make_pair(currentState.value(), state);
            if (transitions.find(transitionKey) != transitions.end()) {
                transitions[transitionKey](); // Execute the transition lambda
            }
        }

        currentState = state; // Update the current state
    }

    // Executes the action associated with the current state.
    void update() {
        if (!currentState.has_value()) {
            throw std::logic_error("No current state set."); // Retain this exception to reflect invalid usage
        }

        auto action = states[currentState.value()].action;
        if (action) {
            action(); // Execute the state action
        }
    }

private:
    struct StateData {
        std::function<void()> action = nullptr; // Action for the state
    };

    std::unordered_map<TState, StateData> states; // Map of states and their associated actions
    std::map<std::pair<TState, TState>, std::function<void()>> transitions; // Map of state transitions
    std::optional<TState> currentState; // Optional to track the current state
};

#endif
