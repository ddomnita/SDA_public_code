//
// Created by Dan Domnita on 14.03.2023.
//

#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct STACK_STR{
    STACK_ENTRY *top;
    unsigned int size;
}STACK;

STACK *create_stack() {
    STACK *stack = (STACK *)malloc(sizeof(STACK));

    if (stack != NULL) {
        stack->top = NULL;
        stack->size = 0;
    }

    return stack;
}

void delete_stack(STACK **stack) {
    if (stack == NULL || *stack == NULL) {
        return;
    }

    free(*stack);
    *stack = NULL;
}

unsigned int stack_get_size(STACK *stack) {
    if (stack == NULL) {
        return 0;
    }

    return stack->size;
}

void push(STACK *stack, STACK_ENTRY *entry) {
    if (stack == NULL || entry == NULL) {
        return;
    }

    entry->next = stack->top;
    stack->top = entry;
    stack->size ++;
}

STACK_ENTRY *pop(STACK *stack) {
    STACK_ENTRY *entry = NULL;

    do {
        if (stack == NULL || stack->top == NULL) {
            break;
        }

        entry = stack->top;

        stack->top = entry->next;
        stack->size --;

        entry->next = NULL;
    } while (false);

    return entry;
}
