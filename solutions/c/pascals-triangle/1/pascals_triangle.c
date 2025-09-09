#include "pascals_triangle.h"

#include <stdlib.h>

void free_triangle(uint8_t **triangle, size_t rows) {
    for (size_t i = 0; i < rows; i++) {
        free(triangle[i]);
    }
    free(triangle);
}

uint8_t **create_triangle(size_t rows) {
    uint8_t **triangle = calloc(rows > 0 ? rows : 1, sizeof(uint8_t*));

    if (rows <= 0) {
        triangle[0] = calloc(1, sizeof(uint8_t));
        return triangle;
    }

    for (size_t i = 0; i < rows; i++) {
        triangle[i] = calloc(rows, sizeof(uint8_t));
    }

    for (size_t i = 0; i < rows; i++) {
        int left = 0;
        int right = i;
        triangle[i][left] = 1;
        triangle[i][right] = 1;
        while (++left <= --right) {
            triangle[i][left] = triangle[i - 1][left] + triangle[i - 1][left - 1];
            triangle[i][right] = triangle[i][left];
        }
    }

    return triangle;
}