//
// Created by Dan Domnita on 22.04.2023.
//

#include "int_stack.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    int data;
    STACK_ENTRY s_entry;
}STACK_INT_NODE;


STACK_INT_NODE *create_s_node(int val) {
    STACK_INT_NODE *node = (STACK_INT_NODE *) malloc(sizeof(STACK_INT_NODE));

    if (node != NULL) {
        memset(node, 0, sizeof(STACK_INT_NODE));

        node->data = val;
    }

    return node;
}

void push_int(STACK *stack, int val) {
    if (stack == NULL) {
        return;
    }

    STACK_INT_NODE *node = create_s_node(val);

    if (node != NULL) {
        push(stack, &node->s_entry);
    }
}

int pop_int(STACK *stack) {
    int val = INT_MIN;
    STACK_ENTRY *entry = NULL;
    STACK_INT_NODE *node = NULL;

    do {
        if (stack == NULL) {
            break;
        }

        entry = pop(stack);
        if (entry == NULL) {
            break;
        }

        node = CONTAINING_RECORD(entry, STACK_INT_NODE, s_entry);
        val = node->data;

        free(node);
        node = NULL;
    } while (false);

    return val;
}

