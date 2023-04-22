//
// Created by Dan Domnita on 14.03.2023.
//

#ifndef SDA_STACK_H__
#define SDA_STACK_H__

#ifndef CONTAINING_RECORD
#define CONTAINING_RECORD(address, type, field) (\
    (type *)((char*)(address) -(size_t)(&((type *)0)->field)))
#endif

typedef struct STACK_ENTRY_STR{
    struct STACK_ENTRY_STR *next;
}STACK_ENTRY;

typedef struct STACK_STR STACK;

/// Create a structure of type stack
/// @return A pointer to a structure of type STACK. NULL will be return in case of error.
STACK *create_stack();

/// It will free the structure created by create_stack function.
/// @pre The stack has to be empty before the functions call.
/// @param queue A double pointer to a structure of type STACK. After the call it is guaranteed that the pointer will be NULL.
void delete_stack(STACK **stack);

/// Retrieves the size of a stack.
/// @param stack The stack for which the size is needed.
/// @return The size of the stack.
unsigned int stack_get_size(STACK *stack);

/// Adds an entry in the stack
/// @param stack The stack to which an element will be added.
/// @param entry The element to be added.
void push(STACK *stack, STACK_ENTRY *entry);

/// Removes an element from the stack.
/// @param stack The stack from which to remove the element.
/// @return The element removed from the queue.
STACK_ENTRY *pop(STACK *stack);

#endif //SDA_STACK_H__
