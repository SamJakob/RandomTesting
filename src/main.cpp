//
// Created by Sam M. on 4/20/22.
//

#include <iostream>
#include <iomanip>

#include "xxh3.h"

void printStringHash(const char* str, size_t length, const char* label);

void printStringHash(const char* str, size_t length) {
    return printStringHash(str, length, nullptr);
}

void printStringHash(const char* str, size_t length, const char* label) {
    uint64_t result = XXH3_64bits(str, length);
    // Print the result as a hex value.
    std::cout << "0x" << std::hex << std::setw(16) << std::setfill('0') << result
              // Switch back to decimal.
              << std::dec
              // Then, print the value as a label.
              << "\t:\t\t" << (label != nullptr ? label : str) << " (" << length << ")" << std::endl;
}

void printBufferHash(uint8_t* buffer, size_t length) {
    uint64_t result = XXH3_64bits(buffer, length);
    // Print the result as a hex value.
    std::cout << "0x" << std::hex << std::setw(16) << std::setfill('0') << result
              // Switch back to decimal.
              << std::dec
              // Then, print the value as a label.
              << "\t:\t\t" << "<" << (buffer != nullptr ? "buffer" : "nullptr") << "> (" << length << ")" << std::endl;
}

void printIntRangeHash(size_t max) {
    uint8_t bytesRange[max];
    for (size_t i = 0; i < max; i++) bytesRange[i] = i % 256;
    printBufferHash(bytesRange, max);
}

int main(int argc, const char** argv) {
    // Basic values (Strings)
    printBufferHash(nullptr, 0);
    printStringHash("\0", 1, "null");
    printStringHash("ye", 2);
    printStringHash("hello", 5);
    printStringHash("howdy yall", 10);
    printStringHash("Hello, world!", 13);
    printStringHash("Howdy, partners! tree mushrooms", 31);

    // 130 bytes.
    printIntRangeHash(130);
    printIntRangeHash(163);

    // 250 bytes.
    printIntRangeHash(250);

    // 2048 bytes.
    printIntRangeHash(2048);

    return 0;
}
