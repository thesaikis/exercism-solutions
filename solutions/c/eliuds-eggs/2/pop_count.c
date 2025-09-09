#include "pop_count.h"

unsigned int egg_count(unsigned int n) {
    return n > 0 ? 1 + egg_count(n & (n - 1)) : 0;
}