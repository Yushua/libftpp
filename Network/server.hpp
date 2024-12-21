#ifndef SERVER_HPP
#define SERVER_HPP

#include "./network.hpp"
#include <unordered_map>
#include <vector>
#include <functional>
#include <iostream>

class Server {
public:
    // Start the server
    void start(const size_t& port);

    // Define an action for a specific message type
    void defineAction(const Message::Type& messageType, const std::function<void(long long& clientID, const Message& msg)>& action);

    // Send a message to a specific client
    void sendTo(const Message& message, long long clientID);

    // Send a message to an array of clients
    void sendToArray(const Message& message, const std::vector<long long>& clientIDs);

    // Send a message to all connected clients
    void sendToAll(const Message& message);

    // Update the server, process received messages
    void update();

private:
    std::unordered_map<Message::Type, std::function<void(long long& clientID, const Message& msg)>> actions_;
    // Simulated client connections (for demonstration purposes)
    std::vector<long long> connectedClients_;
};

#endif