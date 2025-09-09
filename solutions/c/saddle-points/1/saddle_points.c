#include "saddle_points.h"

#include <stdio.h>
#include <stdbool.h>

static bool is_max_in_row(int rows, int cols, uint8_t matrix[rows][cols], int m_r, int m_c) {
    for (int c = 0; c < cols; c++) {
        if (c == m_c) {
            continue;
        } else if (matrix[m_r][c] > matrix[m_r][m_c]) {
            return false;
        }
    }

    return true;
}

static bool is_min_in_col(int rows, int cols, uint8_t matrix[rows][cols], int m_r, int m_c) {
    for (int r = 0; r < rows; r++) {
        if (r == m_r) {
            continue;
        } else if (matrix[r][m_c] < matrix[m_r][m_c]) {
            return false;
        }
    }

    return true;
}

saddle_points_t* saddle_points(int rows, int cols, uint8_t matrix[rows][cols]) {
    saddle_points_t* res_points = malloc(sizeof(saddle_points_t));
    int count = 0;
    
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (is_max_in_row(rows, cols, matrix, r, c) && is_min_in_col(rows, cols, matrix, r, c)) count++;
        }
    }

    res_points->points = malloc(sizeof(saddle_point_t) * count);
    res_points->count = count;

    int index = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (is_max_in_row(rows, cols, matrix, r, c) && is_min_in_col(rows, cols, matrix, r, c)) {
                res_points->points[index] = (saddle_point_t) {r+1, c+1};
                index++;
            }
        }
    }
    
    return res_points;
}

void free_saddle_points(saddle_points_t *saddle_points) {
    free(saddle_points->points);
    free(saddle_points);
    saddle_points = NULL;
}