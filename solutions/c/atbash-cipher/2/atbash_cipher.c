#include "atbash_cipher.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

static void generic_atbash(const char *input, char *output, int space) {
    int out_idx = 0;

    for (; *input; input++) {
        if (isdigit(*input))
            output[out_idx++] = *input;
        else if (isalpha(*input))
            output[out_idx++] = 'z' - tolower(*input) + 'a';

        if (space && (out_idx + 1) % 6 == 0) output[out_idx++] = ' ';
    }

    if (out_idx > 0 && output[out_idx - 1] == ' ') output[out_idx - 1] = '\0';
}

char *atbash_encode(const char *input) {
    size_t input_len = strlen(input);
    char *output = calloc(input_len + (input_len / 5) + 1, sizeof(char));
    generic_atbash(input, output, 1);
    return output;
}

char *atbash_decode(const char *input) {
    size_t input_len = strlen(input);
    char *output = calloc(input_len + 1, sizeof(char));
    generic_atbash(input, output, 0);
    return output;
}