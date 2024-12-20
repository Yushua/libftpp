#ifndef DATA_BUFFER_HPP
#define DATA_BUFFER_HPP

#include <vector>
#include <string>
#include <stdexcept>
#include <type_traits>
#include <cstring>
#include <iostream>

class DataBuffer {
private:

    std::vector<char> buffer;

    size_t readPos = 0;

public:
    // Default constructor initializes an empty buffer
    DataBuffer() = default;

    // Templated method to serialize (write) any trivially copyable type into the buffer
    template <typename T>
    DataBuffer& operator<<(const T& data) {
        static_assert(std::is_trivially_copyable<T>::value, "Only trivially copyable types are supported.");
        const char* rawData = reinterpret_cast<const char*>(&data);
        buffer.insert(buffer.end(), rawData, rawData + sizeof(T));
        return *this;
    }

    // Specialized method to serialize a string into the buffer
    DataBuffer& operator<<(const std::string& str);

    // Templated method to deserialize (read) any trivially copyable type from the buffer
    template <typename T>
    DataBuffer& operator>>(T& data) {
        static_assert(std::is_trivially_copyable<T>::value, "Only trivially copyable types are supported.");
        if (readPos + sizeof(T) > buffer.size()) {
            throw std::out_of_range("Attempt to read past the end of the buffer.");
        }
        std::memcpy(&data, buffer.data() + readPos, sizeof(T));
        readPos += sizeof(T);
        return *this;
    }

    // Specialized method to deserialize a string from the buffer
    DataBuffer& operator>>(std::string& str);

    // Clears the buffer and resets the read position
    void clear();

    // Returns the size of the buffer
    size_t size() const;
};

#endif
