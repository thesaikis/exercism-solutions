#include "rotational_cipher.h"

#include <stdlib.h>
#include <string.h>

char *rotate(const char *text, int shift_key) {
    int len = strlen(text);
    char *res = calloc(len + 1, sizeof(char));

    for (int i = 0; i < len; i++) {
        if (('a' <= text[i] && text[i] <= 'z') ||
            ('A' <= text[i] && text[i] <= 'Z')) {
            char base = 'a' <= text[i] ? 'a' : 'A';
            res[i] = (((text[i] - base) + shift_key) % 26) + base;
        } else
            res[i] = text[i];
    }

    return res;
}