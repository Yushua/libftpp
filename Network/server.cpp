#include "./network.hpp"

void Server::start(const size_t& port) {
    // Simulate starting the server
    std::cout << "Server started on port " << port << std::endl;
    // Add a simulated client for demonstration purposes
    connectedClients_.push_back(1);
}

void Server::defineAction(const Message::Type& messageType, const std::function<void(long long& clientID, const Message& msg)>& action) {
    actions_[messageType] = action;
}

void Server::sendTo(const Message& message, long long clientID) {
    // Simulate sending a message to a specific client
    std::cout << "Sending message of type " << message.type() << " to client " << clientID << std::endl;
}

void Server::sendToArray(const Message& message, const std::vector<long long>& clientIDs) {
    for (long long clientID : clientIDs) {
        sendTo(message, clientID);
    }
}

void Server::sendToAll(const Message& message) {
    for (long long clientID : connectedClients_) {
        sendTo(message, clientID);
    }
}

void Server::update() {
    // Simulate receiving messages and executing defined actions
    // Normally, this would involve network communication
    for (long long clientID : connectedClients_) {
        // Simulate received messages
        Message msg1(1);
        msg1 << 42; // Example value
        if (actions_.find(1) != actions_.end()) {
            actions_[1](clientID, msg1);
        }

        Message msg2(2);
        std::string str = "Hello";
        msg2 << str.size();
        for (char c : str) {
            msg2 << c;
        }
        if (actions_.find(2) != actions_.end()) {
            actions_[2](clientID, msg2);
        }
    }
}