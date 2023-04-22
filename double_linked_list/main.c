//
// Created by Dan Domnita on 20.03.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "double_linked_list.h"

typedef struct {
    int x;
    int y;
    DLL_ENTRY dll_entry;
}POINT_2D;

POINT_2D *create_point_2d(int x, int y) {
    POINT_2D *point = (POINT_2D*)malloc(sizeof(POINT_2D));

    if (point != NULL) {
        memset(point, 0, sizeof(POINT_2D));

        point->x = x;
        point->y = y;
    }

    return point;
}

void print_list(DL_LIST *list) {
    POINT_2D *point = NULL;

    for (DLL_ENTRY *entry = dll_get_first(list); entry != NULL; entry = entry->next) {
        point = CONTAINING_RECORD(entry, POINT_2D, dll_entry);

        printf("(%d, %d) ", point->x, point->y);
    }
    printf(" -> size: %d\n", dll_get_size(list));
}

int main()
{
    DL_LIST *list = NULL;
    POINT_2D *point = NULL;
    DLL_ENTRY *entry = NULL;

    const int MAX_ENTRIES = 4;

    list = dll_create_list();
    if (list == NULL) {
        perror("Error creating list!\n");
        return -1;
    }

    for(int i = MAX_ENTRIES - 1; i >= 0; i--) {
        point = create_point_2d(i, i);

        dll_insert_first(list, &point->dll_entry);
    }
    print_list(list);


    for(int i = 0; i < MAX_ENTRIES; i++) {
        point = create_point_2d(i, i);

        dll_insert_last(list, &point->dll_entry);
    }
    print_list(list);


    entry = dll_remove_first(list);
    if (entry != NULL) {
        point = CONTAINING_RECORD(entry, POINT_2D, dll_entry);

        printf("Remove first: (%d, %d)\n", point->x, point->y);
        free(point);
    }
    print_list(list);

    entry = dll_remove_last(list);
    if (entry != NULL) {
        point = CONTAINING_RECORD(entry, POINT_2D, dll_entry);

        printf("Remove last: (%d, %d)\n", point->x, point->y);
        free(point);
    }
    print_list(list);


    entry = dll_get_first(list);
    if (entry != NULL) {
        point = create_point_2d(0, 0);

        dll_insert_before(list, &point->dll_entry, entry);
    }
    print_list(list);

    entry = dll_get_last(list);
    if (entry != NULL) {
        point = create_point_2d(MAX_ENTRIES-1, MAX_ENTRIES-1);

        dll_insert_after(list, &point->dll_entry, entry);
    }
    print_list(list);

    entry = dll_get_first(list);
    if (entry != NULL) {
        dll_remove_element(list, entry);
    }
    print_list(list);

    entry = dll_get_last(list);
    if (entry != NULL) {
        dll_remove_element(list, entry);
    }
    print_list(list);

    entry = dll_get_first(list);
    entry = entry->next;
    entry = entry->next;
    if (entry != NULL) {
        dll_remove_element(list, entry);
    }
    print_list(list);

    entry = dll_remove_first(list);
    while (entry != NULL) {
        point = CONTAINING_RECORD(entry, POINT_2D, dll_entry);
        free(point);
        point = NULL;

        entry = dll_remove_first(list);
    }

    dll_delete_list(&list);

    return 0;
}
