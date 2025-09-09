#include "grains.h"

uint64_t square(uint8_t index) {
    if (index < 1) return 0;
    
    uint64_t grains = 1;
    for (int i = 1; i < index; i++) {
        grains += grains;
    }

    return grains;
}

uint64_t total(void) {
    uint64_t sum = 1;
    uint64_t grains = 1;
    
    for (int i = 1; i <= 64; i++) {
        grains += grains;
        sum += grains;
    }

    return sum;
}