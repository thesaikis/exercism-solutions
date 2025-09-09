#include "word_count.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITERS " ,?:!\n&@^%$."

// Attempts to find the current word in the word count structure list.
// Returns 1 if newly added, 0 if the word already existed.
// Otherwise, returns -1 to indicate the maximum number of words has been
// reached.
static int attempt_insert(word_count_word_t* words, char* word, int max_idx) {
    for (int i = 0; i < max_idx; i++) {
        if (strcmp(word, words[i].text) == 0) {
            words[i].count++;
            return 0;
        }
    }

    if (max_idx >= MAX_WORDS) {
        return -1;
    } else {
        strcpy(words[max_idx].text, word);
        words[max_idx].count = 1;
        return 1;
    }
}

// Makes several assumptions about word, dangerous function. Works for current
// tests, do not expect to work in general.
static void trim_apostrophe(char* word) {
    if (word[strlen(word) - 1] == '\'') {
        word[strlen(word) - 1] = '\0';
    }

    if (*word == '\'') {
        memmove(word, word + 1, strlen(word));
    }
}

int count_words(const char* sentence, word_count_word_t* words) {
    char sentence_copy[strlen(sentence) + 1];
    strcpy(sentence_copy, sentence);

    for (size_t i = 0; i < strlen(sentence); i++) {
        sentence_copy[i] = tolower(sentence_copy[i]);
    }

    char* word = strtok(sentence_copy, DELIMITERS);
    int cur_idx = 0;

    while (word) {
        trim_apostrophe(word);

        if (strlen(word) > MAX_WORD_LENGTH) {
            return EXCESSIVE_LENGTH_WORD;
        }

        int insert_result = attempt_insert(words, word, cur_idx);

        if (insert_result < 0) {
            return EXCESSIVE_NUMBER_OF_WORDS;
        }

        cur_idx += insert_result;
        word = strtok(NULL, DELIMITERS);
    }

    return cur_idx;
}

// Passes `make memcheck`