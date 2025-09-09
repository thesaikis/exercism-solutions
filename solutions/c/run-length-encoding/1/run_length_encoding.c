#include "run_length_encoding.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int write_to_output(char *output, int count, char current_char,
                           int bytes_written) {
    if (count > 1)
        return sprintf(output + bytes_written, "%d%c", count, current_char);
    output[bytes_written] = current_char;
    return 1;
}

char *encode(const char *text) {
    char *output = calloc(MAX_OUTPUT_LEN, sizeof(char));
    char current_char;
    int count = 0;
    int bytes_written = 0;

    for (current_char = *text; *text; text++) {
        if (*text != current_char) {
            bytes_written +=
                write_to_output(output, count, current_char, bytes_written);
            current_char = *text;
            count = 0;
        }
        count++;
    }

    write_to_output(output, count, current_char, bytes_written);

    return output;
}

char *decode(const char *data) {
    char *output = calloc(MAX_OUTPUT_LEN, sizeof(char));
    int count = 0;
    int bytes_written = 0;

    for (; *data; data++) {
        if (*data >= '0' && *data <= '9') {
            count = count * 10 + (*data - '0');
        } else {
            memset(output + bytes_written, *data,
                   sizeof(char) * (count > 1 ? count : 1));
            bytes_written += (count > 1 ? count : 1);
            count = 0;
        }
    }

    return output;
}