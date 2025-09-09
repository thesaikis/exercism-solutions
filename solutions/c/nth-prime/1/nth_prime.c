#include "nth_prime.h"

uint32_t nth(uint32_t n) {
    if (n < 2) return !n ? 0 : 2;

    uint32_t found = 1;
    uint32_t prime = 3;

    for (; found < n; prime += 2) {
        int is_prime = 1;
        for (uint32_t i = 2; i * i <= prime; i++) {
            if (prime % i == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) found++;
    }

    return prime - 2;
}