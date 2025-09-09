#include "reverse_string.h"

#include <string.h>
#include <stdlib.h>

char *reverse(const char *value) {
    int length = strlen(value);
    int end = length - 1;

    char* reversed = malloc(sizeof(char) * length);

    for (int start = 0; start <= end; start++, end--) {
        reversed[start] = value[end];
        reversed[end] = value[start];
    }

    return reversed;
}