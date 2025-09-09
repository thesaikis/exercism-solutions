#include "square_root.h"

double square_root(int radicand) {
    if (radicand < 0) return -1;
    if (radicand == 0) return 0.0;

    double x = radicand;
    double y = 0;
    double prev_y = -1;

    while (prev_y != y) {
        prev_y = y;
        y = (x + radicand / x) / 2;
        x = y;
    }

    return y;
}