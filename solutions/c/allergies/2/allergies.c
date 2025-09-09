#include "allergies.h"

#include <stdlib.h>
#include <string.h>

bool is_allergic_to(allergen_t allergen, int score) {
    return score & 1 << allergen;
}

allergen_list_t get_allergens(int score) {
    allergen_list_t res = {0};

    for (allergen_t i = ALLERGEN_EGGS; i <= ALLERGEN_CATS; i++) {
        if (is_allergic_to(i, score)) {
            res.allergens[i] = true;
            res.count++;
        }
    }

    return res;
}