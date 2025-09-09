#include "pig_latin.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool is_special(const char *word) {
    return !strncmp(word, "xr", 2) || !strncmp(word, "yt", 2);
}

static bool is_vowel(char c) {
    switch (c) {
        case 'a': case 'e': case 'i':
        case 'o': case 'u':
            return true;
        default:
            return false;
    }
}

char *translate(const char *phrase) {
    char *output = calloc(100, sizeof(char));
    char *phrase_cpy = calloc(strlen(phrase), sizeof(char));
    strcpy(phrase_cpy, phrase);
    int len = strlen(phrase_cpy);
    char *word = strtok(phrase_cpy, " ");

    while (word) {
        if (is_vowel(word[0]) || is_special(word)) {
            sprintf(output, "%say", word);
        } else {
            for (int i = 1; i < len; i++) {
                if (is_vowel(word[i]) || word[i] == 'y') {
                    if (word[i] == 'u' && word[i - 1] == 'q') i++;

                    strcat(output, word + i);
                    strncat(output, word, i);
                    strcat(output, "ay");
                    break;
                }
            }
        }

        word = strtok(NULL, " ");

        if (word) strcat(output, " ");
    }

    free(phrase_cpy);
    return output;
}