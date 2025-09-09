#include "pop_count.h"

unsigned int egg_count(unsigned int n) {
    return n > 0 ? (n & 1) + egg_count(n >> 1) : 0;
}