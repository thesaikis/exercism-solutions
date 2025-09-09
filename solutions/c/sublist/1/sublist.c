#include "sublist.h"

#include <stdlib.h>

static int is_sublist(int *a, int *b, size_t a_count, size_t b_count) {
    if (!a) return 1;
    if (!b) return 0;

    size_t a_idx = 0;
    size_t start_idx = 0;

    for (size_t b_idx = 0; b_idx < b_count; b_idx++) {
        if (b[b_idx] == a[a_idx]) {
            a_idx++;
            if (a_idx == a_count) return 1;
        } else {
            b_idx = start_idx;
            start_idx++;
            a_idx = 0;
        }
    }

    return 0;
}

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count) {
    int list_to_base =
        is_sublist(list_to_compare, base_list, list_to_compare_element_count,
                   base_list_element_count);
    int base_to_list =
        is_sublist(base_list, list_to_compare, base_list_element_count,
                   list_to_compare_element_count);

    if (list_to_base && base_to_list) return EQUAL;
    if (base_to_list) return SUPERLIST;
    if (list_to_base) return SUBLIST;

    return UNEQUAL;
}