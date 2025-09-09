#include "roman_numerals.h"

#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10
#define NUM_NUMERALS 13

static const char* numerals[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                 "XL", "X",  "IX", "V",  "IV", "I"};
static const unsigned int values[] = {1000, 900, 500, 400, 100, 90, 50,
                                      40,   10,  9,   5,   4,   1};

char* to_roman_numeral(unsigned int number) {
    char* output = calloc(MAX_LENGTH, sizeof(char));

    for (int i = 0; i < NUM_NUMERALS; i++) {
        while (number >= values[i]) {
            strcat(output, numerals[i]);
            number -= values[i];
        }
    }

    return output;
}