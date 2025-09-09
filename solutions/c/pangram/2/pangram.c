#include "pangram.h"

#include <ctype.h>

#define ALPHABET_LEN 26

bool is_pangram(const char *sentence) {
    if (!sentence) return false;

    bool letters_found[ALPHABET_LEN] = { false };

    while (*sentence) {
        char lowercase_char = tolower(*sentence);
        if (isalpha(lowercase_char)) {
            letters_found[lowercase_char - 'a'] = true;
        }
        sentence++;
    }

    for (int i = 0; i < ALPHABET_LEN; i++) {
        if (!letters_found[i]) return false;
    }

    return true;
}
