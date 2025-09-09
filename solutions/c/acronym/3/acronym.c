#include "acronym.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* abbreviate(const char* phrase) {
    if (!phrase || !phrase[0]) return NULL;

    size_t len = strlen(phrase);
    char* result = calloc(len + 1, sizeof(char));
    char* p = result;

    char phrase_copy[len + 1];
    strncpy(phrase_copy, phrase, len + 1); // Copy the '\0' !!!

    for (char* split = strtok(phrase_copy, "-_ "); split; split = strtok(NULL, "-_ ")) {
        *p = toupper(*split);
        p++;
    }

    return result;
}