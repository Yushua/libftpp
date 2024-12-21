#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <sstream>

class Message {
public:
    using Type = int;

    Message(Type type) : type_(type) {}
    Message() : type_(0) {}

    Type type() const {
        return type_;
    }

    template<typename T>
    Message& operator<<(const T& data) {
        buffer_ << data << " ";
        return *this;
    }

    template<typename T>
    const Message& operator>>(T& data) const {
        buffer_ >> data;
        return *this;
    }

private:
    Type type_;
    mutable std::stringstream buffer_;
};

#endif