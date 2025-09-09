#include "sieve.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
    bool *is_prime = calloc(limit - 1, sizeof(bool));
    memset(is_prime, true, (limit - 1) * sizeof(bool));

    uint32_t count = 0;
    uint32_t cur_prime = 2;

    while (count < max_primes && cur_prime <= limit) {
        count++;
        primes[count - 1] = cur_prime;

        uint32_t mul_prime = cur_prime * 2;
        while (mul_prime <= limit) {
            is_prime[mul_prime - 2] = false;
            mul_prime += cur_prime;
        }

        cur_prime++;
        while (cur_prime <= limit && !is_prime[cur_prime - 2]) {
            cur_prime++;
        }
    }

    return count;
}