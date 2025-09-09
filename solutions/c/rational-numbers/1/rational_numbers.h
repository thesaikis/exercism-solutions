#ifndef RATIONAL_NUMBERS_H
#define RATIONAL_NUMBERS_H

#include <inttypes.h>

typedef struct {
    int numerator;
    int denominator;
} rational_t;

rational_t add(rational_t r1, rational_t r2);
rational_t subtract(rational_t r1, rational_t r2);
rational_t multiply(rational_t r1, rational_t r2);
rational_t divide(rational_t r1, rational_t r2);
rational_t absolute(rational_t r);
rational_t exp_rational(rational_t r, int16_t n);
float exp_real(float x, rational_t r);
rational_t reduce(rational_t r);

#endif
