#include "../includes/libftpp.hpp"
#include <iostream>

int main() {
    // Create a message of type 1 and insert an integer
    Message msg1(1);
    int number = 42;
    msg1 << number;

    // Deserialize the integer from the message
    int extractedNumber;
    msg1 >> extractedNumber;
    std::cout << "Message type: " << msg1.type() << ", extracted number: " << extractedNumber << std::endl;

    // Create a message of type 2 and insert a string
    Message msg2(2);
    std::string str = "Hello, World!";
    msg2 << str.size();
    for (char c : str) {
        msg2 << c;
    }

    // Deserialize the string from the message
    size_t strSize;
    msg2 >> strSize;
    std::string extractedStr;
    extractedStr.reserve(strSize);
    for (size_t i = 0; i < strSize; ++i) {
        char c;
        msg2 >> c;
        extractedStr.push_back(c);
    }
    std::cout << "Message type: " << msg2.type() << ", extracted string: " << extractedStr << std::endl;

    return 0;
}