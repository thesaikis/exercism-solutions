#include "triangle.h"

static bool is_valid(triangle_t t) {
    return t.a + t.b >= t.c && t.b + t.c >= t.a && t.a + t.c >= t.b &&
           t.a * t.b * t.c > 0;
}

bool is_equilateral(triangle_t t) {
    return t.a == t.b && t.b == t.c && is_valid(t);
}

bool is_isosceles(triangle_t t) { 
    return !is_scalene(t) && is_valid(t); 
}

bool is_scalene(triangle_t t) {
    return t.a != t.b && t.b != t.c && t.a != t.c && is_valid(t);
}