#include <stddef.h>
#ifndef KNAPSACK_H
#define KNAPSACK_H

typedef struct {
    unsigned int weight;
    unsigned int value;
} item_t;

unsigned int maximum_value(unsigned int, item_t[], size_t);

#endif
