#include "rail_fence_cipher.h"

#include <stdlib.h>
#include <string.h>

static char* railCipher(char* input, size_t rails, int isEncoding) {
    int length = strlen(input);
    char* output = malloc(sizeof(char) * (length + 1));
    output[length] = '\0';

    int maxGap = 2 * (int)rails - 2;
    int outputIdx = 0;

    for (size_t i = 0; i < rails; i++) {
        int idx = (int)i;
        int curGap = maxGap - 2 * i;

        if (i == rails - 1) {
            curGap = maxGap;
        }

        while (idx < length) {
            if (isEncoding) {
                output[outputIdx] = input[idx];
            } else {
                output[idx] = input[outputIdx];
            }
            idx += curGap;
            outputIdx++;

            if (i != 0 && i != rails - 1) {
                curGap = maxGap - curGap;
            }
        }
    }

    return output;
}

char* encode(char* text, size_t rails) { 
    return railCipher(text, rails, 1); 
}

char* decode(char* ciphertext, size_t rails) {
    return railCipher(ciphertext, rails, 0);
}
