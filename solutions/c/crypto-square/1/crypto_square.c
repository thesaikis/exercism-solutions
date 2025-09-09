#include "crypto_square.h"

#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

char *ciphertext(const char *input) {
    char *clean = calloc(strlen(input) + 1, sizeof(char));
    int clean_idx = 0;

    for (; *input; input++)
        if (isalnum(*input)) clean[clean_idx++] = tolower(*input);

    int col = ceil(sqrt(clean_idx));
    int row = floor(sqrt(clean_idx));
    if (row * col < clean_idx) {
        row = col;
    }

    char *final = calloc(row * col + col, sizeof(char));
    int final_idx = 0;

    for (int i = 0; i < col; i++) {
        for (int j = i; j < row * col; j += col) {
            if (j >= clean_idx)
                final[final_idx++] = ' ';
            else
                final[final_idx++] = clean[j];
        }
        if (i < col - 1) final[final_idx++] = ' ';
    }

    free(clean);
    return final;
}
