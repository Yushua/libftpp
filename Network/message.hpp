#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <sstream>

class Message {
public:
    using Type = int;

    Message(Type type) : _type(type) {}
    Message() : _type(0) {}

    Type type() const {
        return _type;
    }

    template<typename T>
    Message& operator<<(const T& data) {
        _buffer << data << " ";
        return *this;
    }

    template<typename T>
    const Message& operator>>(T& data) const {
        _buffer >> data;
        return *this;
    }

private:
    Type _type;
    mutable std::stringstream _buffer;
};

#endif