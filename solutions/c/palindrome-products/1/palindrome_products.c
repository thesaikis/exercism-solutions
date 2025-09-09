#include "palindrome_products.h"

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static int is_palindrome(int num) {
    int div = pow(10, ((int)log10(num)));

    while (num != 0) {
        int leading = num / div;
        if (leading != num % 10) return 0;
        num = (num % div) / 10;
        div /= 100;
    }

    return 1;
}

void generate_factors(factor_t **p, int num, int from, int to) {
    factor_t *cur = NULL;
    int sqrt_num = sqrt(num);

    for (int i = from; i <= (to < sqrt_num ? to : sqrt_num); i++) {
        if (num % i == 0) {
            int quotient = num / i;
            if (quotient >= from && quotient <= to) {
                factor_t *new_node = malloc(sizeof(factor_t));
                new_node->factor_a = i;
                new_node->factor_b = quotient;
                new_node->next = NULL;

                if (cur == NULL) {
                    *p = new_node;
                } else {
                    cur->next = new_node;
                }
                cur = new_node;
            }
        }
    }
}

product_t *get_palindrome_product(int from, int to) {
    product_t *result = calloc(1, sizeof(product_t));

    if (to < from) {
        sprintf(result->error, "invalid input: min is %d and max is %d", from,
                to);
        return result;
    }

    result->smallest = INT_MAX;
    result->largest = INT_MIN;

    for (int i = from; i <= to; i++) {
        for (int j = i; j <= to; j++) {
            int product = i * j;
            if (is_palindrome(product)) {
                if (product > result->largest) result->largest = product;

                if (product < result->smallest) {
                    result->smallest = product;
                    break;  // No smaller value will be found, safe to break!
                }
            }
        }
    }

    if (result->smallest == INT_MAX && result->largest == INT_MIN) {
        sprintf(result->error,
                "no palindrome with factors in the range %d to %d", from, to);
        return result;
    }

    generate_factors(&(result->factors_sm), result->smallest, from, to);
    generate_factors(&(result->factors_lg), result->largest, from, to);

    return result;
}

void free_product(product_t *p) {
    if (!p) return;

    factor_t *to_free = NULL;

    while ((to_free = p->factors_sm) != NULL) {
        p->factors_sm = p->factors_sm->next;
        free(to_free);
    }

    while ((to_free = p->factors_lg) != NULL) {
        p->factors_lg = p->factors_lg->next;
        free(to_free);
    }

    free(p);
}