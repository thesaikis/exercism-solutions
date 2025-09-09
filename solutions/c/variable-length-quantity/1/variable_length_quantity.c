#include "variable_length_quantity.h"
#include <stdint.h>
#include <stdbool.h>

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output) {
    // write to `output`, return final output's length
    // `output` buffer should be enough to hold the full result

    int res_idx = 0;
    bool set_msb = false;
    int left = 0;
    int right;

    for (size_t i = 0; i < integers_len; i++) {
        uint32_t tgt = integers[i];
        left = res_idx;
        while (true) {
            int byte = tgt & 0x7F;
            tgt >>= 7;
            if (set_msb) {
                byte |= 0x80;
            }
            output[res_idx++] = byte;
            set_msb = true;
            if (tgt == 0) break;
        }
        set_msb = false;
        right = res_idx - 1;

        while (left < right) {
            uint8_t tmp = output[left];
            output[left++] = output[right];
            output[right--] = tmp;
        }
    }

    return res_idx;
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output) {
    // write to `output`, return final output's length
    // return -1 if error
    // `output` buffer should be enough to hold the full result
    int res_idx = 0;
    uint32_t val = 0;

    for (size_t i = 0; i < buffer_len; i++) {
        val <<= 7;
        val |= bytes[i] & 0x7F;
        if (!(bytes[i] & 0x80)) {
            output[res_idx++] = val;
            val = 0;
        }
    }

    if ((val != 0) | (res_idx == 0)) res_idx = -1;

    return res_idx;
}
