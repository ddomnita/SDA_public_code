//
// Created by Dan Domnita on 12.03.2023.
//

#include "single_linked_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct SL_LIST_STR{
    SLL_ENTRY *first;
    SLL_ENTRY *last;
    int size;
}SL_LIST;


SL_LIST *sll_create_list() {
    SL_LIST *list = NULL;

    list = (SL_LIST *)malloc(sizeof(SL_LIST));
    if (list != NULL) {
        memset(list, 0, sizeof(SL_LIST));
    }

    return list;
}

void sll_destroy_list(SL_LIST **list) {
    if (list == NULL) {
        return;
    }

    if (*list == NULL) {
        return;
    }

    free(*list);
    *list = NULL;
}

SLL_ENTRY *sll_get_first(const SL_LIST *list) {
    if (list == NULL) {
        return NULL;
    }

    return list->first;
}

SLL_ENTRY *sll_get_last(const SL_LIST *list) {
    if (list == NULL) {
        return NULL;
    }

    return list->last;
}

int sll_get_size(const SL_LIST *list) {
    if (list == NULL) {
        return -1;
    }

    return list->size;
}

bool sll_search_entry(SL_LIST *list, SLL_ENTRY *entry, SLL_ENTRY **prev_entry) {
    if (list == NULL || entry == NULL) {
        if (prev_entry != NULL) {
            *prev_entry = NULL;
        }
        return false;
    }

    SLL_ENTRY *iter = list->first;
    SLL_ENTRY *prev = NULL;
    bool found = false;

    while (iter != NULL) {
        if (iter == entry) {
            found = true;
            break;
        }

        prev = iter;
        iter = iter->next;
    }

    if (prev_entry != NULL) {
        if (found) {
            *prev_entry = prev;
        } else {
            *prev_entry = NULL;
        }
    }

    return found;
}

void sll_insert_first(SL_LIST *list, SLL_ENTRY *entry) {
    if (list == NULL) {
        return;
    }

    entry->next = list->first;
    list->first = entry;

    if (list->last == NULL) {
        list->last = entry;
    }

    list->size ++;
}

void sll_insert_last(SL_LIST *list, SLL_ENTRY *entry) {
    if (list == NULL) {
        return;
    }
    entry->next = NULL;

    if (list->last == NULL) {
        list->first = list->last = entry;
    } else {
        list->last->next = entry;
        list->last = entry;
    }

    list->size ++;
}

void sll_insert_before(SL_LIST *list, SLL_ENTRY *entry, SLL_ENTRY *before_entry) {
    if (list == NULL || entry == NULL || before_entry == NULL) {
        return;
    }

    SLL_ENTRY *prev = NULL;
    bool found = sll_search_entry(list, before_entry, &prev);

    if (found == false) {
        return;
    }

    list->size ++;
    entry->next = before_entry;
    if (prev != NULL) {
        prev->next = entry;
    }
    if (before_entry == list->first) {
        list->first = entry;
    }
}

void sll_insert_after(SL_LIST *list, SLL_ENTRY *entry, SLL_ENTRY *after_entry) {
    if (list == NULL || entry == NULL || after_entry == NULL) {
        return;
    }

    bool found = sll_search_entry(list, after_entry, NULL);

    if (found == false) {
        return;
    }

    list->size ++;
    entry->next = after_entry->next;
    after_entry->next = entry;

    if (after_entry == list->last) {
        list->last = entry;
    }
}

SLL_ENTRY *sll_remove_first(SL_LIST *list) {
    if (list == NULL) {
        return NULL;
    }

    SLL_ENTRY * entry = list->first;

    if (list->first == list->last) {
        list->first = list->last = NULL;
    } else {
        list->first = entry->next;
        entry->next = NULL;
    }

    list->size --;

    return entry;
}

SLL_ENTRY *sll_remove_last(SL_LIST *list) {
    if (list == NULL) {
        return NULL;
    }

    SLL_ENTRY * entry = list->last;
    SLL_ENTRY *prev_entry = NULL;

    if (list->first == list->last) {
        list->first = list->last = NULL;
    } else {
        entry = list->first;
        while (entry != NULL && entry->next != NULL) {
            prev_entry = entry;
            entry = entry->next;
        }

        prev_entry->next = NULL;
        list->last = prev_entry;
    }

    list->size --;

    return entry;
}

SLL_ENTRY *sll_remove_element(SL_LIST *list, SLL_ENTRY *entry) {
    if (list == NULL || entry == NULL) {
        return NULL;
    }

    SLL_ENTRY *prev = NULL;
    bool found = sll_search_entry(list, entry, &prev);

    if (found == false) {
        return NULL;
    }

    list->size --;
    if (entry == list->first) {
        if (entry == list->last) {
            list->first = list->last = NULL;
        } else {
            list->first = entry->next;
            entry->next = NULL;
        }
    } else {
        if (entry == list->last) {
            list->last = prev;
            prev->next = NULL;
        } else { // entry is in the middle
            prev->next = entry->next;
            entry->next = NULL;
        }
    }

    return entry;
}








