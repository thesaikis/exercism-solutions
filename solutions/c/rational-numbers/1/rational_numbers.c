#include "rational_numbers.h"

#include <stdlib.h>
#include <math.h>

int gcd(int, int);
int gcd(int a, int b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}

rational_t add(rational_t r1, rational_t r2) {
    rational_t res = {r1.numerator * r2.denominator + r2.numerator * r1.denominator, 
                      r1.denominator * r2.denominator};
    return reduce(res);
}

rational_t subtract(rational_t r1, rational_t r2) {
    rational_t res = {r1.numerator * r2.denominator - r2.numerator * r1.denominator, 
                      r1.denominator * r2.denominator};
    return reduce(res);
}

rational_t multiply(rational_t r1, rational_t r2) {
    rational_t res = {r1.numerator * r2.numerator, 
                      r1.denominator * r2.denominator};
    return reduce(res);
}

rational_t divide(rational_t r1, rational_t r2) {
    rational_t res = {r1.numerator * r2.denominator, 
                      r1.denominator * r2.numerator};
    return reduce(res);
}

rational_t absolute(rational_t r) {
    rational_t res = {abs(r.numerator), abs(r.denominator)};
    return reduce(res);
}

rational_t exp_rational(rational_t r, int16_t n) {
    rational_t res;
    if (n > 0) {
        res = (rational_t) {pow(r.numerator, n), pow(r.denominator, n)};
    } else {
        res = (rational_t) {pow(r.denominator, -n), pow(r.numerator, -n)};
    }
    return reduce(res);
}

float exp_real(float x, rational_t r) {
    return pow(x, (float) r.numerator / r.denominator);
}

rational_t reduce(rational_t r) {
    int divisor = gcd(r.numerator, r.denominator);

    r.numerator /= divisor;
    r.denominator /= divisor;

    if (r.denominator < 0) {
        r.numerator = -r.numerator;
        r.denominator = abs(r.denominator);
    }

    return r;
}