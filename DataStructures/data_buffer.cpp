#include "data_buffer.hpp"

// Serializes a string into the buffer.
// The string's length is stored first, followed by its contents.
DataBuffer& DataBuffer::operator<<(const std::string& str) {
    size_t length = str.size();
    *this << length; // Serialize the length of the string
    buffer.insert(buffer.end(), str.begin(), str.end()); // Serialize the actual string data
    return *this;
}

// Deserializes a string from the buffer.
// Reads the string's length first, then reads the corresponding number of characters.
DataBuffer& DataBuffer::operator>>(std::string& str) {
    size_t length;
    *this >> length; // Deserialize the length of the string

    if (readPos + length > buffer.size()) {
        throw std::out_of_range("Attempt to read past the end of the buffer.");
    }

    str.assign(buffer.begin() + readPos, buffer.begin() + readPos + length);
    readPos += length; // Update the read position
    return *this;
}

// Clears the buffer and resets the read position to zero.
void DataBuffer::clear() {
    buffer.clear();
    readPos = 0;
}

// Returns the current size of the buffer (number of bytes stored).
size_t DataBuffer::size() const {
    return buffer.size();
}
