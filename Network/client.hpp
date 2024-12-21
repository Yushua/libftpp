#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "./message.hpp"
#include <string>
#include <functional>
#include <unordered_map>
#include <iostream>

class Client {
public:
    void connect(const std::string& address, const size_t& port);
    void disconnect();
    void defineAction(const Message::Type& messageType, const std::function<void(const Message& msg)>& action);
    void send(const Message& message);
    void update();

private:
    std::unordered_map<Message::Type, std::function<void(const Message& msg)>> actions_;
    bool connected_ = false;
};

#endif // CLIENT_HPP