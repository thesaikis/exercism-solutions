#include "minesweeper.h"

#include <stdlib.h>
#include <string.h>

char **annotate(const char **minefield, const size_t rows) {
    if (!minefield) return NULL;

    char **annotation = calloc(rows, sizeof(char *));
    size_t len = strlen(minefield[0]);
    annotation[0] = calloc(rows * (len + 1), sizeof(char));

    for (size_t i = 0; i < rows; i++) {
        if (i > 0) annotation[i] = annotation[i - 1] + len + 1;

        for (size_t j = 0; j < len; j++) {
            annotation[i][j] = minefield[i][j];

            if (annotation[i][j] == '*') continue;

            int mines = 0;

            for (int y = -1; y <= 1; y++) {
                if (i + y >= rows) continue;
                for (int x = -1; x <= 1; x++) {
                    if (j + x >= len) continue;
                    mines += minefield[i + y][j + x] == '*';
                }
            }

            if (mines > 0) annotation[i][j] = mines + '0';
        }
    }

    return annotation;
}

void free_annotation(char **annotation) {
    free(*annotation);
    free(annotation);
}