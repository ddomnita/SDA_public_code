//
// Created by Dan Domnita on 22.04.2023.
//

#ifndef STACK_INT_STACK_H
#define STACK_INT_STACK_H

#include "stack.h"

/// Adds an int in the stack
/// @param stack The stack to which an element will be added.
/// @param entry The element to be added.
void push_int(STACK *stack, int val);

/// Removes an int from the stack.
/// @param stack The stack from which to remove the element.
/// @return The element removed from the queue. If the stack is NULL or empty, INT_MIN is returned;
int pop_int(STACK *stack);

#endif //STACK_INT_STACK_H
