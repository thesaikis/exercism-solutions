#include "collatz_conjecture.h"

int steps(int start) {
    if (start < 1) return -1;

    int count = 0;
    for (; start > 1; count++) {
        start = start % 2 ? 3 * start + 1 : start / 2;
    }

    return count;
}