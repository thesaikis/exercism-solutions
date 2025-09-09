#include "spiral_matrix.h"

#include <stdlib.h>

spiral_matrix_t *spiral_matrix_create(int size) {
    spiral_matrix_t *mat = malloc(sizeof(spiral_matrix_t));
    mat->size = size;

    if (size < 1) {
        mat->matrix = NULL;
        return mat;
    }

    mat->matrix = calloc(size, sizeof(int *));
    for (int i = 0; i < size; i++) {
        mat->matrix[i] = calloc(size, sizeof(int));
    }

    int dx = 1, dy = 0;
    int x = 0, y = 0;

    for (int i = 0; i < size * size; i++) {
        mat->matrix[y][x] = i + 1;

        if (x + dx < 0 || x + dx >= size || y + dy < 0 || y + dy >= size ||
            mat->matrix[y + dy][x + dx] != 0) {
            int temp = dx;
            dx = -dy;
            dy = temp;
        }

        x += dx;
        y += dy;
    }

    return mat;
}

void spiral_matrix_destroy(spiral_matrix_t *mat) {
    if (mat->matrix) {
        for (int i = 0; i < mat->size; i++) free(mat->matrix[i]);
        free(mat->matrix);
    }
    free(mat);
}