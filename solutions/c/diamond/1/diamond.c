#include "diamond.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

char **make_diamond(const char letter) {
    int size = 2 * (letter - 'A') + 1;

    char **diamond = calloc(size, sizeof(char *));

    for (int i = 0; i < size; i++) {
        diamond[i] = calloc(size + 1, sizeof(char));

        for (int j = 0; j < size; j++) {
            if (abs(j - (letter - 'A')) == i ||
                abs(j - (letter - 'A')) == 2 * (letter - 'A') - i)
                diamond[i][j] = letter - abs(i - (letter - 'A'));
            else
                diamond[i][j] = ' ';
        }
    }

    return diamond;
}

void free_diamond(char **diamond) {
    size_t size = diamond[0] ? strlen(diamond[0]) : 0;
    for (size_t i = 0; i < size; i++) {
        free(diamond[i]);
    }
    free(diamond);
}