#include "sum_of_multiples.h"

#include <stdio.h>
#include <stdlib.h>

unsigned int sum(const unsigned int* factors, const size_t number_of_factors,
                 const unsigned int limit) {
    int* found = calloc(limit, sizeof(int));
    unsigned int sum = 0;

    for (size_t i = 0; i < number_of_factors; i++) {
        for (unsigned int f = factors[i]; f != 0 && f < limit; f += factors[i]) {
            if (!found[f - 1]) sum += f;
            found[f - 1] = f;
        }
    }

    free(found);
    return sum;
}