#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "int_stack.h"

typedef struct {
    int x;
    int y;
    STACK_ENTRY s_entry;
}POINT;

typedef struct {
    int x;
    int y;
    int z;
    STACK_ENTRY s_entry;
}POINT3d;

POINT *create_point(int x, int y) {
    POINT *point = malloc(sizeof(POINT));

    if (point != NULL) {
        memset(point, 0, sizeof(POINT));
        point->x = x;
        point->y = y;
    }

    return point;
}

int main() {
    POINT *point = NULL;
    STACK_ENTRY *entry = NULL;
    STACK *stack = NULL;
    STACK *int_stack = NULL;

    printf("Test STACK:\n");

    stack = create_stack();

    for (int i = 0; i < 10; i++) {
        point = create_point(i, i);
        push(stack, &point->s_entry);
    }

    printf("Stack size: %d\n", stack_get_size(stack));

    for (int i = 0; i < 10; i++) {
        entry = pop(stack);
        if (entry != NULL) {
            point = CONTAINING_RECORD(entry, POINT, s_entry);

            printf("(%d, %d) ", point->x, point->y);

            free(point);
            point = NULL;
        }
    }
    printf("\n");

    delete_stack(&stack);

    printf("\nTest int STACK:\n");

    int_stack = create_stack();

    for (int i = 0; i < 10; i++) {
        push_int(int_stack, i);
    }

    printf("Stack size: %d\n", stack_get_size(int_stack));

    for (int i = 0; i < 10; i++) {
        printf("%d ", pop_int(int_stack));
    }
    printf("\n");

    delete_stack(&int_stack);

    return 0;
}
