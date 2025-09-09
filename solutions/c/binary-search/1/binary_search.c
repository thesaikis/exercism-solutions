#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length) {
    int low = 0, high = length - 1;

    while (low <= high) {
        int index = low + (high - low) / 2;
        if (arr[index] == value) {
            return &arr[index];
        } else if (value < arr[index]) {
            high = index - 1;
        } else {
            low = index + 1;
        }
    }

    return NULL;
}