#include "scrabble_score.h"

static unsigned int letter_score(char let) {
    switch (let) {
        case 'q': case 'z': return 10;
        case 'j': case 'x': return 8;
        case 'k': return 5;
        case 'f': case 'h': case 'v': case 'w': case 'y': return 4;
        case 'b': case 'c': case 'm': case 'p': return 3;
        case 'd': case 'g': return 2;
        default: return 1;
    }
}

unsigned int score(const char *word) {
    unsigned int score = 0;
    for (; *word; word++) {
        score += letter_score(*word <= 'Z' ? *word + 32 : *word);
    }
    return score;
}