#include "acronym.h"

#include <stdlib.h>
#include <stdbool.h>

char *abbreviate(const char *phrase) {
    if (!phrase || !phrase[0]) return NULL;

    size_t count = 1;
    bool check_let = false;
    
    for (int i = 0; phrase[i]; i++) {
        if (phrase[i] == ' ' || phrase[i] == '-' || phrase[i] == '_') check_let = true;
        else if (check_let == true && ((phrase[i] >= 'a' && phrase[i] <= 'z') || (phrase[i] >= 'A' && phrase[i] <= 'Z'))) {
            count++;
            check_let = false;
        }
    }

    char *acronym = calloc(sizeof(char), count + 1);

    acronym[0] = phrase[0];
    int index = 1;
    
    for (int i = 0; phrase[i]; i++) {
        if (phrase[i] == ' ' || phrase[i] == '-' || phrase[i] == '_') check_let = true;
        else if (check_let == true && ((phrase[i] >= 'a' && phrase[i] <= 'z') || (phrase[i] >= 'A' && phrase[i] <= 'Z'))) {
            acronym[index++] = phrase[i] <= 'Z' ? phrase[i] : phrase[i] - ' ';
            check_let = false;
        }
    }

    return acronym;
}