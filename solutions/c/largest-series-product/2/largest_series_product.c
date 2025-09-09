#include "largest_series_product.h"

#include <ctype.h>
#include <string.h>

int64_t largest_series_product(char *digits, size_t span) {
    size_t digits_len = strlen(digits);
    if (digits_len < span || span < 1) return -1;
    int64_t max = -1;

    for (size_t i = 0; i <= digits_len - span; i++) {
        int64_t product = 1;
        for (size_t j = i; j < i + span; j++) {
            if (!isdigit(digits[j])) return -1;
            product *= digits[j] - '0';
        }
        max = product > max ? product : max;
    }

    return max;
}