#include "DataStructure.hpp"


DataBuffer& DataBuffer::operator<<(const std::string& str) {
    size_t length = str.size();
    *this << length;
    buffer.insert(buffer.end(), str.begin(), str.end()); 
    return *this;
}

DataBuffer& DataBuffer::operator>>(std::string& str) {
    size_t length;
    *this >> length;

    if (readPos + length > buffer.size()) {
        throw std::out_of_range("Attempt to read past the end of the buffer.");
    }

    str.assign(buffer.begin() + readPos, buffer.begin() + readPos + length);
    readPos += length;
    return *this;
}

void DataBuffer::clear() {
    buffer.clear();
    readPos = 0;
}

size_t DataBuffer::size() const {
    return buffer.size();
}
