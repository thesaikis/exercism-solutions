#include "secret_handshake.h"

#include <stdlib.h>
#include <string.h>

static int fourBitSum(size_t num) {
    int count = 0;

    for (int i = 0; i < 4 && num > 0; i++) {
        count += num & 1;
        num >>= 1;
    }

    return count;
}

const char** commands(size_t number) {
    int length = fourBitSum(number);

    if (length == 0) {
        const char** res = malloc(1);
        res[0] = NULL;
        return res;
    }

    int reverse = number & 16;
    const char** res = malloc(sizeof(char*) * length);

    int index = reverse ? length - 1 : 0;
    if (number & 1) {
        res[index] = "wink";
        index += reverse ? -1 : 1;
    }
    if (number & 2) {
        res[index] = "double blink";
        index += reverse ? -1 : 1;
    }
    if (number & 4) {
        res[index] = "close your eyes";
        index += reverse ? -1 : 1;
    }
    if (number & 8) {
        res[index] = "jump";
    }

    return res;
}
