#include "reverse_string.h"

#include <string.h>
#include <stdlib.h>

char *reverse(const char *value) {
    int length = strlen(value);
    char* reversed = calloc(length + 1, sizeof(char));

    for (int start = 0, end = length - 1; start <= end; start++, end--) {
        reversed[start] = value[end];
        reversed[end] = value[start];
    }

    return reversed;
}