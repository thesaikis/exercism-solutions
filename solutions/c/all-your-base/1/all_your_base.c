#include "all_your_base.h"

#include <math.h>

size_t rebase(int8_t *digits, int16_t input_base, int16_t output_base,
              size_t input_length) {
    if (!input_length || input_base < 2 || output_base < 2) return 0;
    int out_idx = 0;

    int middle_conv = 0;

    for (size_t i = 0; i < input_length; i++) {
        if (digits[i] < 0 || digits[i] >= input_base) return 0;
        middle_conv += digits[i] * pow(input_base, input_length - i - 1);
    }

    if (middle_conv == 0) digits[out_idx++] = 0;

    for (int exp = log(middle_conv) / log(output_base); exp >= 0; exp--) {
        int divisor = pow(output_base, exp);
        int digit = middle_conv / divisor;
        digits[out_idx++] = digit;
        middle_conv %= divisor;
    }

    return out_idx;
}