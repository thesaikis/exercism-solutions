#include "zebra_puzzle.h"

#include <stdbool.h>
#include <stdlib.h>

#define NUM_HOUSES 5

typedef enum { ENGLAND, SPAIN, UKRAINE, NORWAY, JAPAN } NATION;
typedef enum { RED, GREEN, IVORY, YELLOW, BLUE } COLOR;
typedef enum { DOG, SNAIL, FOX, HORSE, ZEBRA } PET;
typedef enum { COFFEE, TEA, MILK, ORANGE_JUICE, WATER } DRINK;
typedef enum { OLD_GOLD, KOOL, CHESTERFIELD, LUCKY_STRIKE, PARLIAMENT } CIGAR;

static bool permute(int indices[NUM_HOUSES], int values[NUM_HOUSES]) {
    int i = NUM_HOUSES - 1;
    while (i > 0 && indices[i - 1] >= indices[i]) {
        i--;
    }

    if (i <= 0) {
        return false;
    }

    int j = NUM_HOUSES - 1;
    while (indices[j] <= indices[i - 1]) {
        j--;
    }

    int temp = indices[i - 1];
    indices[i - 1] = indices[j];
    indices[j] = temp;

    j = NUM_HOUSES - 1;
    while (i < j) {
        temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
        i++;
        j--;
    }

    for (int k = 0; k < NUM_HOUSES; k++) {
        values[indices[k]] = k;
    }

    return true;
}

solution_t solve_puzzle() {
    NATION water_drinker = -1;
    NATION zebra_owner = -1;

    int house_colors[] = {RED, GREEN, IVORY, YELLOW, BLUE};
    int index_colors[] = {0, 1, 2, 3, 4};

    do {
        // Rule 6
        if (index_colors[GREEN] - 1 != index_colors[IVORY]) continue;

        int house_nation[] = {ENGLAND, SPAIN, UKRAINE, NORWAY, JAPAN};
        int index_nation[] = {0, 1, 2, 3, 4};

        do {
            // Rule 2
            if (index_nation[ENGLAND] != index_colors[RED]) continue;

            // Rule 10
            if (index_nation[NORWAY] != 0) continue;

            // Rule 15
            if (abs(index_nation[NORWAY] - index_colors[BLUE]) != 1) continue;

            int house_pet[] = {DOG, SNAIL, FOX, HORSE, ZEBRA};
            int index_pet[] = {0, 1, 2, 3, 4};

            do {
                // Rule 3
                if (index_nation[SPAIN] != index_pet[DOG]) continue;

                int house_drink[] = {COFFEE, TEA, MILK, ORANGE_JUICE, WATER};
                int index_drink[] = {0, 1, 2, 3, 4};

                do {
                    // Rule 4
                    if (index_drink[COFFEE] != index_colors[GREEN]) continue;

                    // Rule 5
                    if (index_nation[UKRAINE] != index_drink[TEA]) continue;

                    // Rule 9
                    if (index_drink[MILK] != 2) continue;

                    int house_cigar[] = {OLD_GOLD, KOOL, CHESTERFIELD,
                                         LUCKY_STRIKE, PARLIAMENT};
                    int index_cigar[] = {0, 1, 2, 3, 4};

                    do {
                        // Rule 7
                        if (index_cigar[OLD_GOLD] != index_pet[SNAIL]) continue;

                        // Rule 8
                        if (index_cigar[KOOL] != index_colors[YELLOW]) continue;

                        // Rule 11
                        if (abs(index_cigar[CHESTERFIELD] - index_pet[FOX]) !=
                            1)
                            continue;

                        // Rule 12
                        if (abs(index_cigar[KOOL] - index_pet[HORSE]) != 1)
                            continue;

                        // Rule 13
                        if (index_cigar[LUCKY_STRIKE] !=
                            index_drink[ORANGE_JUICE])
                            continue;

                        // Rule 14
                        if (index_cigar[PARLIAMENT] != index_nation[JAPAN])
                            continue;

                        water_drinker = house_nation[index_drink[WATER]];
                        zebra_owner = house_nation[index_pet[ZEBRA]];

                    } while (permute(index_cigar, house_cigar));
                } while (permute(index_drink, house_drink));
            } while (permute(index_pet, house_pet));
        } while (permute(index_nation, house_nation));
    } while (permute(index_colors, house_colors));

    const char* nation_names[] = {"English", "Spanish", "Ukrainian",
                                  "Norwegian", "Japanese"};

    return (solution_t){nation_names[water_drinker], nation_names[zebra_owner]};
}