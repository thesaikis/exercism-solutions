#include "anagram.h"

#include <ctype.h>
#include <string.h>

#define ALPHABET_LEN 26

static int is_anagram(const char *subject, const char *candidate) {
    int sub_len = strlen(subject);
    int cand_len = strlen(candidate);

    if (sub_len != cand_len) return 0;

    int sub_freq[ALPHABET_LEN] = {0};
    int cand_freq[ALPHABET_LEN] = {0};
    int any_diff_flag = 0;

    for (int i = 0; i < sub_len; i++) {
        any_diff_flag |= tolower(subject[i]) != tolower(candidate[i]);
        sub_freq[tolower(subject[i]) - 'a']++;
        cand_freq[tolower(candidate[i]) - 'a']++;
    }

    if (!any_diff_flag) return 0;

    for (int i = 0; i < ALPHABET_LEN; i++) {
        if (sub_freq[i] != cand_freq[i]) return 0;
    }

    return 1;
}

void find_anagrams(const char *subject, struct candidates *candidates) {
    for (size_t i = 0; i < candidates->count; i++) {
        struct candidate *cand = &(candidates->candidate[i]);
        cand->is_anagram =
            is_anagram(subject, cand->word) ? IS_ANAGRAM : NOT_ANAGRAM;
    }
}