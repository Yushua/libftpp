#include "data_buffer.hpp"

// Serialize a string into the buffer
DataBuffer& DataBuffer::operator<<(const std::string& str) {
    size_t length = str.size();
    *this << length; // Serialize the length of the string first
    buffer.insert(buffer.end(), str.begin(), str.end());
    return *this;
}

// Deserialize a string from the buffer
DataBuffer& DataBuffer::operator>>(std::string& str) {
    size_t length;
    *this >> length; // Deserialize the length of the string first

    if (readPos + length > buffer.size()) {
        throw std::out_of_range("Attempt to read past the end of the buffer.");
    }

    str.assign(buffer.begin() + readPos, buffer.begin() + readPos + length);
    readPos += length;
    return *this;
}

// Clears the buffer
void DataBuffer::clear() {
    buffer.clear();
    readPos = 0;
}

// Returns the size of the buffer
size_t DataBuffer::size() const {
    return buffer.size();
}