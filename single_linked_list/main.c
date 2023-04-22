#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "single_linked_list.h"

typedef struct {
    int x;
    int y;
    SLL_ENTRY entry;
}POINT_2D;

POINT_2D *create_point(int x, int y) {
    POINT_2D *point = NULL;

    point = (POINT_2D *)malloc(sizeof(POINT_2D));
    if (point != NULL) {
        memset(point, 0, sizeof(POINT_2D));

        point->x = x;
        point->y = y;
    }

    return point;
}

void print_list(SL_LIST *list) {
    POINT_2D *point = NULL;

    for (SLL_ENTRY *entry = sll_get_first(list); entry != NULL; entry = entry->next) {
        point = CONTAINING_RECORD(entry, POINT_2D, entry);

        printf("(%d, %d) ", point->x, point->y);
    }

    printf(" -> size: %d\n", sll_get_size(list));
}

int main() {
    SL_LIST *list = NULL;
    SLL_ENTRY *entry = NULL;
    POINT_2D *point = NULL;

    POINT_2D *tmp1 = NULL;
    POINT_2D *tmp2 = NULL;

    list = sll_create_list();

    for(int i = 3; i >= 0; i--) {
        point = create_point(i, i);
        sll_insert_first(list, &point->entry);
    }

    print_list(list);

    for(int i = 0; i < 4; i++) {
        point = create_point(i, i);
        sll_insert_last(list, &point->entry);
    }

    print_list(list);

    tmp1 = create_point(-2, -2);
    tmp2 = create_point(-1, -1);

    entry = sll_get_first(list);

    sll_insert_before(list, &tmp1->entry, entry);
    sll_insert_before(list, &tmp2->entry, entry);

    print_list(list);

    sll_remove_element(list, &tmp1->entry);
    sll_remove_element(list, &tmp2->entry);
    free(tmp1);
    free(tmp2);

    print_list(list);

    tmp1 = create_point(5, 5);
    tmp2 = create_point(4, 4);

    entry = sll_get_last(list);

    sll_insert_after(list, &tmp1->entry, entry);
    sll_insert_after(list, &tmp2->entry, entry);

    print_list(list);

    sll_remove_element(list, &tmp1->entry);
    sll_remove_element(list, &tmp2->entry);
    free(tmp1);
    free(tmp2);

    print_list(list);



    for(int i = 0; i < 4; i++) {
        entry = sll_remove_last(list);

        if (entry != NULL) {
            point = CONTAINING_RECORD(entry, POINT_2D, entry);

            free(point);
        }
    }

    print_list(list);

    for(int i = 3; i >= 0; i--) {
        entry = sll_remove_first(list);

        if (entry != NULL) {
            point = CONTAINING_RECORD(entry, POINT_2D, entry);

            free(point);
        }
    }

    sll_destroy_list(&list);

    return 0;
}
