#include "wordy.h"

#include <stdio.h>
#include <string.h>

static bool do_operation(int *result, char *operation, int operand) {
    if (strcmp(operation, "plus") == 0)      *result += operand;
    else if (strcmp(operation, "minus") == 0) *result -= operand;
    else if (strcmp(operation, "divided") == 0) *result /= operand;
    else if (strcmp(operation, "multiplied") == 0) *result *= operand;

    return false;
}

bool answer(const char *question, int *result) {
    if (strncmp(question, "What is ", 8) != 0) {
        return false;
    }

    size_t input_len = strlen(question);
    char q_copy[input_len];
    q_copy[input_len - 1] = '\0';

    // Does not copy the final character '?'
    strncpy(q_copy, question, input_len - 1);

    // Add 8 to q_copy inside to skip "What is "
    char *word = strtok(q_copy + 8, " ");

    if (sscanf(word, "%d", result) != 1) return false;

    while ((word = strtok(NULL, " ")) != NULL) {
        char *operator = word;
        int operand;

        if (!(word = strtok(NULL, " "))) return false;
        if (strcmp(word, "by") == 0) word = strtok(NULL, " ");
        if (!word || sscanf(word, "%d", &operand) != 1) return false;

        do_operation(result, operator, operand);
    }

    return true;
}