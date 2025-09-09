#include "largest_series_product.h"

#include <ctype.h>
#include <string.h>

static int64_t product(char *digits, size_t span) {
    int64_t product = 1;
    for (size_t i = 0; i < span; i++) {
        if (!isdigit(digits[i])) return -1;
        product *= digits[i] - '0';
    }
    return product;
}

int64_t largest_series_product(char *digits, size_t span) {
    size_t digits_len = strlen(digits);
    if (digits_len < span || span < 1) return -1;
    int64_t max = -1;

    for (size_t i = 0; i <= digits_len - span; i++) {
        int64_t calc = product(digits + i, span);
        if (calc < 0) return -1;
        max = calc > max ? calc : max;
    }

    return max;
}