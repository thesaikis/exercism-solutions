#include "say.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

const char* large[] = {"billion", "million", "thousand"};
const char* small[] = {"twenty", "thirty",  "forty",  "fifty",
                       "sixty",  "seventy", "eighty", "ninety"};
const char* tiny[] = {"one",     "two",       "three",    "four",     "five",
                      "six",     "seven",     "eight",    "nine",     "ten",
                      "eleven",  "twelve",    "thirteen", "fourteen", "fifteen",
                      "sixteen", "seventeen", "eighteen", "nineteen"};

int say(int64_t input, char** ans) {
    if (input < MIN_SAY || input > MAX_SAY) return -1;

    *ans = calloc(MAX_SAY_LENGTH, sizeof(char));
    int64_t divisor = 1000000000;
    int large_idx = 0;
    int written = 0;

    while (divisor >= 1) {
        int group = input / divisor;

        if (group > 0) {
            int hundreds = group / 100;

            if (hundreds > 0) written += sprintf(*ans + written, "%s hundred ", tiny[hundreds - 1]);

            group -= hundreds * 100;
            int tens = group / 10;

            if (tens == 1) {
                written += sprintf(*ans + written, "%s ", tiny[group - 1]);
            } else {
                if (tens > 0)  written += sprintf(*ans + written, "%s", small[tens - 2]);

                int ones = group - tens * 10;
                if (ones > 0) written += sprintf(*ans + written, "%s%s ", tens > 0 ? "-" : "", tiny[ones - 1]);
            }

            if (large_idx < 3) written += sprintf(*ans + written, "%s ", large[large_idx]);
        }

        input %= divisor;
        divisor /= 1000;
        large_idx++;
    }

    if ((*ans)[written - 1] == ' ') (*ans)[written - 1] = '\0';
    if (written == 0) sprintf(*ans, "zero");

    return 0;
}