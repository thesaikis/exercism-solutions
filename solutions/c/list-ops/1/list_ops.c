#include "list_ops.h"

#include <stdlib.h>

list_t *new_list(size_t length, list_element_t elements[]) {
    list_t *list = malloc(sizeof(list_t) + sizeof(list_element_t) * length);
    
    list->length = length;
    for (size_t i = 0; i < length; i++) {
        list->elements[i] = elements[i];
    }

    return list;
}

list_t *append_list(list_t *list1, list_t *list2) {
    size_t l1 = length_list(list1);
    size_t l2 = length_list(list2);
    list_element_t elements[l1 + l2];

    size_t i = 0;
    for (; i < l1; i++) {
        elements[i] = list1->elements[i];
    }

    for (size_t j = 0; j < l2; j++) {
        elements[i + j] = list2->elements[j];
    }

    return new_list(l1 + l2, elements);
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
    int count = 0;

    for (size_t i = 0; i < length_list(list); i++) {
        if (filter(list->elements[i])) count++;
    }

    int index = 0;
    list_element_t elements[count];

    for (size_t i = 0; i < length_list(list); i++) {
        if (filter(list->elements[i])) {
            elements[index] = list->elements[i];
            index++;
        }
    }

    return new_list(count, elements);
}

size_t length_list(list_t *list) {
    return list->length;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
    list_element_t elements[length_list(list)];

    for (size_t i = 0; i < length_list(list); i++) {
        elements[i] = map(list->elements[i]);
    }

    return new_list(length_list(list), elements);
}

list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {
    for (size_t i = 0; i < length_list(list); i++) {
        initial = foldl(initial, list->elements[i]);
    }

    return initial;
}

list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {
    for (int i = length_list(list) - 1; i >= 0; i--) {
        initial = foldr(list->elements[i], initial);
    }

    return initial;
}

list_t *reverse_list(list_t *list) {
    list_element_t elements[length_list(list)];

    for (size_t i = 0; i < length_list(list); i++) {
        elements[length_list(list) - i - 1] = list->elements[i];
    }

    return new_list(length_list(list), elements);
}

void delete_list(list_t *list) {
    free(list);
    list = NULL;
}