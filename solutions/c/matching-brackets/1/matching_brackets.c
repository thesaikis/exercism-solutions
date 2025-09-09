#include "matching_brackets.h"

struct Stack {
    int data[100];
    int top;
};

static int push(struct Stack *stack, char d) {
    stack->data[stack->top++] = d;
    return 1;
}

static int pop(struct Stack *stack) {
    if (stack->top == 0) {
        return -1;
    }
    int d = stack->data[--stack->top];

    return d;
}

bool is_paired(const char *input) {
    struct Stack parenStack = {{0}, 0};

    for (; *input; input++) {
        if (*input == '{' || *input == '(' || *input == '[') {
            push(&parenStack, *input);
        } else if (*input == '}' || *input == ')' || *input == ']') {
            int success = pop(&parenStack);
            if (success == -1) {
                return false;
            } else if (success + 1 != *input && success + 2 != *input) {
                return false;
            }
        }
    }

    return parenStack.top == 0;
}
