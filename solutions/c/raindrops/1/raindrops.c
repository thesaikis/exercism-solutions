#include "raindrops.h"

#include <stdio.h>
#include <string.h>

static const int NUM_DROPS = 3;
static const int factors[] = {3, 5, 7};
static const char* drop_names[] = {"Pling", "Plang", "Plong"};

char* convert(char result[], int drops) {
    for (int i = 0; i < NUM_DROPS; i++) {
        if (drops % factors[i] == 0) strcat(result, drop_names[i]);
    }

    if (result[0] == '\0') sprintf(result, "%d", drops);
    return result;
}