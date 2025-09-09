#include "isogram.h"

#include <stdbool.h>
#include <string.h>

#define ALPHABET_LEN 26

bool is_isogram(const char phrase[]) {
    if (!phrase) return false;
    
    bool letters_seen[ALPHABET_LEN] = {false};

    int length = strlen(phrase);
    
    for (int i = 0; i < length; i++) {
        char let = phrase[i];

        // Check if the character is actually in the alphabet
        if ((let >= 'A' && let <= 'Z') || (let >= 'a' && let <= 'z')) {
            // Convert to a lower case character, if it is upper case
            if (let >= 'A' && let <= 'Z') {
                let += 'a' - 'A';
            }

            // Check if the letter has been seen
            // Return false if seen, otherwise mark it as seen
            if (letters_seen[let - 'a']) {
                return false;
            } else {
                letters_seen[let - 'a'] = true;
            }
        }
    }
    
    return true;
}