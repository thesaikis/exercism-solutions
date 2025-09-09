#include "binary.h"

int convert(const char *input) {
    int res = 0;

    for ( ; *input; input++) {
        res <<= 1;
        if ((*input) != '0' && (*input) != '1') return INVALID;
        res += (*input) - '0';
    }

    return res;
}