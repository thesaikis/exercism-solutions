#include "high_scores.h"

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <limits.h>

int32_t latest(const int32_t *scores, size_t scores_len) {
    return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
    int32_t best = scores[0];

    for (size_t i = 0; i < scores_len; i++) {
        if (scores[i] > best) {
            best = scores[i];
        }
    }

    return best;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output) {
    int32_t largest[] = {INT32_MIN, INT32_MIN, INT32_MIN};
    size_t length = 0;

    for (size_t i = 0; i < scores_len; i++) {
        if (scores[i] > largest[0]) {
            largest[2] = largest[1];
            largest[1] = largest[0];
            largest[0] = scores[i];
        } else if (scores[i] > largest[1]) {
            largest[2] = largest[1];
            largest[1] = scores[i];
        } else if (scores[i] > largest[2]) {
            largest[2] = scores[i];
        }
    }

    for (int i = 2; i >= 0; i--) {
        if (largest[i] != INT_MIN) {
            length = i + 1;
            break;
        }
    }

    memcpy(output, largest, length * sizeof(int32_t));
    
    return length;
}