#include "series.h"

#include <stdlib.h>
#include <string.h>

slices_t slices(char *input_text, unsigned int substring_length) {
    if (substring_length > MAX_SERIES_LENGTH || substring_length < 1 || !input_text[0]) {
        return (slices_t){.substring = NULL, .substring_count = 0};
    }

    slices_t res = {
        .substring = calloc(MAX_SERIES_RESULTS, sizeof(char *)),
        .substring_count = strlen(input_text) - substring_length + 1};

    for (unsigned int i = 0; i < res.substring_count; i++) {
        res.substring[i] = calloc(substring_length + 1, sizeof(char));
        strncpy(res.substring[i], input_text + i, substring_length);
    }

    return res;
}