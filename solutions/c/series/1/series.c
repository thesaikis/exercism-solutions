#include "series.h"

#include <stdlib.h>
#include <string.h>

slices_t slices(char *input_text, unsigned int substring_length) {
    slices_t res;
    res.substring = calloc(MAX_SERIES_RESULTS, sizeof(char *));
    res.substring_count = 0;

    if (substring_length > MAX_SERIES_LENGTH || substring_length < 1 || !input_text) {
        return res;
    }

    res.substring_count = strlen(input_text) - substring_length + 1;

    for (unsigned int i = 0; i < res.substring_count; i++) {
        res.substring[i] = calloc(MAX_SERIES_LENGTH, sizeof(char));
        strncpy(res.substring[i], input_text + i, substring_length);
    }

    return res;
}