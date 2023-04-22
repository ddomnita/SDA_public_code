//
// Created by Dan Domnita on 20.03.2023.
//

#include "double_linked_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct DL_LIST_STR {
    DLL_ENTRY *first;
    DLL_ENTRY *last;
    unsigned int size;
}DL_LIST;

DL_LIST *dll_create_list() {
    DL_LIST *list = malloc(sizeof(DL_LIST));

    if (list != NULL) {
        memset(list, 0, sizeof(DL_LIST));
    }

    return list;
}

void dll_delete_list(DL_LIST **list) {
    if (list == NULL) {
        return;
    }

    if (*list != NULL) {
        free(*list);
        *list = NULL;
    }
}

DLL_ENTRY *dll_get_first(DL_LIST *list) {
    if (list == NULL) {
        return NULL;
    }

    return list->first;
}

DLL_ENTRY *dll_get_last(DL_LIST *list) {
    if (list == NULL) {
        return NULL;
    }

    return list->last;
}

unsigned int dll_get_size(DL_LIST *list) {
    if (list == NULL) {
        return 0;
    }

    return list->size;
}

bool dll_check_entry_in_list(DL_LIST *list, DLL_ENTRY *entry) {
    bool result = false;
    DLL_ENTRY *iter = NULL;

    do {
        if (list == NULL || entry == NULL) {
            break;
        }

        iter = list->first;
        while (iter != NULL) {
            if (iter == entry) {
                result = true;
                break;
            }

            iter = iter->next;
        }
    } while (false);

    return result;
}

void dll_insert_first(DL_LIST *list, DLL_ENTRY *entry) {
    if (list == NULL || entry == NULL) {
        return;
    }

    entry->next = list->first;
    entry->prev = NULL;

    if (list->first == NULL) {
        list->first = list->last = entry;
    } else {
        list->first->prev = entry;
        list->first = entry;
    }

    list->size ++;
}

void dll_insert_last(DL_LIST *list, DLL_ENTRY *entry) {
    if (list == NULL || entry == NULL) {
        return;
    }

    entry->next = NULL;
    entry->prev = list->last;

    if (list->last == NULL) {
        list->first = list->last = entry;
    } else {
        list->last->next = entry;
        list->last = entry;
    }

    list->size ++;
}



void dll_insert_before(DL_LIST *list, DLL_ENTRY *entry, DLL_ENTRY *before_entry) {
    if (list == NULL || before_entry == NULL || entry == NULL) {
        return;
    }

    // will not check if the before_entry is in the list
    entry->next = before_entry;
    entry->prev = NULL;

    if (before_entry == list->first) {
        before_entry->prev = entry;

        list->first = entry;
    } else {
        if (before_entry->prev == NULL) {
            return;
        }

        entry->prev = before_entry->prev;
        before_entry->prev->next = entry;
        before_entry->prev = entry;
    }

    list->size ++;
}


void dll_insert_after(DL_LIST *list, DLL_ENTRY *entry, DLL_ENTRY *after_entry) {
    if (list == NULL || after_entry == NULL || entry == NULL) {
        return;
    }

    // will not check if the after_entry is in the list
    entry->next = NULL;
    entry->prev = after_entry;

    if (after_entry == list->last) {
        after_entry->next = entry;

        list->last = entry;
    } else {
        if (after_entry->next == NULL) {
            return;
        }

        entry->next = after_entry->next;
        after_entry->next->prev = entry;
        after_entry->next = entry;
    }

    list->size ++;
}

DLL_ENTRY *dll_remove_first(DL_LIST *list) {
    if (list == NULL) {
        return NULL;
    }

    DLL_ENTRY *entry = list->first;

    if (entry != NULL) {
        list->first = entry->next;

        if (entry->next != NULL) {
            entry->next->prev = NULL;
        }

        entry->next = NULL;

        list->size --;
    }

    return entry;
}

DLL_ENTRY *dll_remove_last(DL_LIST *list) {
    if (list == NULL) {
        return NULL;
    }

    DLL_ENTRY *entry = list->last;

    if (entry != NULL) {
        list->last = entry->prev;

        if (entry->prev != NULL) {
            entry->prev->next = NULL;
        }

        entry->prev = NULL;

        list->size --;
    }

    return entry;
}

DLL_ENTRY *dll_remove_element(DL_LIST *list, DLL_ENTRY *entry) {
    if (list == NULL || entry == NULL) {
        return NULL;
    }

    // will not check if the entry is in the list
    if (entry == list->first) {
        if (entry == list->last) {
            list->first = list->last = NULL;
        } else {
            list->first = entry->next;
            list->first->prev = NULL;
        }
    } else {
        if (entry == list->last) {
            list->last = entry->prev;
            list->last->next = NULL;
        } else {
            entry->prev->next = entry->next;
            entry->next->prev = entry->prev;
        }
    }

    list->size --;
    entry->next = entry->prev = NULL;

    return entry;
}
