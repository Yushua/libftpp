#include "./client.hpp"

void Client::connect(const std::string& address, const size_t& port) {
    connected_ = true;
    std::cout << "Connected to server at " << address << ":" << port << std::endl;
}

void Client::disconnect() {
    connected_ = false;
    std::cout << "Disconnected from server" << std::endl;
}

void Client::defineAction(const Message::Type& messageType, const std::function<void(const Message& msg)>& action) {
    actions_[messageType] = action;
}

void Client::send(const Message& message) {
    std::cout << "Sending message of type " << message.type() << " to server" << std::endl;
}

void Client::update() {
    if (connected_) {
        Message msg1(3);
        msg1 << 84; // Example doubled value
        if (actions_.find(3) != actions_.end()) {
            actions_[3](msg1);
        }
    }
}