#include "etl.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

static int comp_new_map(const new_map *a, const new_map *b) {
    return a->key - b->key;
}

int convert(const legacy_map *input, const size_t input_len, new_map **output) {
    int output_len = 0;

    for (size_t i = 0; i < input_len; i++) {
        output_len += strlen(input[i].keys);
    }

    *output = calloc(output_len, sizeof(new_map *));
    int out_idx = 0;

    for (size_t i = 0; i < input_len; i++) {
        for (size_t c = 0; c < strlen(input[i].keys); c++) {
            (*output)[out_idx].key = tolower(input[i].keys[c]);
            (*output)[out_idx].value = input[i].value;
            out_idx++;
        }
    }

    qsort(*output, output_len, sizeof(new_map *),
          (int (*)(const void *, const void *))comp_new_map);

    return output_len;
}