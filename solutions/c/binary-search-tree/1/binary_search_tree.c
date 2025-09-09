#include "binary_search_tree.h"

#include <stdlib.h>

static void insert_data(int data, node_t **node) {
    if (*node == NULL) {
        *node = calloc(1, sizeof(node_t));
        (*node)->data = data;
    } else if (data <= (*node)->data) {
        insert_data(data, &((*node)->left));
    } else {
        insert_data(data, &((*node)->right));
    }
}

static void build_sorted_data(node_t *node, int *sorted_list, int *index) {
    if (node) {
        build_sorted_data(node->left, sorted_list, index);
        sorted_list[(*index)++] = node->data;
        build_sorted_data(node->right, sorted_list, index);
    }
}

node_t *build_tree(int *tree_data, size_t tree_data_len) {
    node_t *root = NULL;

    for (size_t i = 0; i < tree_data_len; i++) {
        insert_data(tree_data[i], &root);
    }

    return root;
}

void free_tree(node_t *tree) {
    if (!tree) return;

    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
}

void tree_size(node_t *node, int *count) {
    if (node) {
        tree_size(node->left, count);
        (*count)++;
        tree_size(node->right, count);
    }
}

int *sorted_data(node_t *tree) {
    int count = 0;
    tree_size(tree, &count);

    int *sorted_list = calloc(count, sizeof(int));
    int index = 0;
    build_sorted_data(tree, sorted_list, &index);

    return sorted_list;
}