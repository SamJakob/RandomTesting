#include <iostream>

#include "constexpr-xxh3.h"

int main() {
//    uint8_t data[120];
//    for (int i = 0; i < 120; i++) data[i] = i;

    int64_t hash = constexpr_xxh3::XXH3_64bits_const("hello");
    std::cout << (int64_t) hash << std::endl;
    return 0;
}
