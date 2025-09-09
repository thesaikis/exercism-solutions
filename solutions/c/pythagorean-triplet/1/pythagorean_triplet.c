#include "pythagorean_triplet.h"

#include <stdlib.h>

triplets_t* triplets_with_sum(uint16_t sum) {
    triplets_t* triplets = malloc(sizeof(triplets_t));

    triplets->count = 0;
    triplets->triplets = NULL;

    for (int a = 1; a < sum / 3; a++) {
        for (int b = a + 1; b < sum / 2; b++) {
            int c = sum - a - b;
            if (a * a + b * b == c * c) {
                triplets->count++;
                triplets->triplets = realloc(triplets->triplets, sizeof(triplet_t) * triplets->count);
                triplets->triplets[triplets->count - 1] = (triplet_t){a, b, c};
            }
        }
    }

    return triplets;
}

void free_triplets(triplets_t *triplets) {
    (void) triplets;
}