//
// Created by Dan Domnita on 12.03.2023.
//

#ifndef __SINGLE_LINKED_LIST_H__
#define __SINGLE_LINKED_LIST_H__

#include <stdbool.h>

#ifndef CONTAINING_RECORD
#define CONTAINING_RECORD(address, type, field) (\
    (type *)((char*)(address) -(size_t)(&((type *)0)->field)))
#endif

typedef struct _SLL_ENTRY{
    struct _SLL_ENTRY *next;
}SLL_ENTRY;

typedef struct _SL_LIST SL_LIST;

///Creates a new single linked list
///@return On success the address of a new list is returned. On error NULL is returned.
SL_LIST *sll_create_list();

///Frees a single linked list
///@pre The elements in the list have to be removed first.
void sll_destroy_list(SL_LIST **list);

///Retrives the address of the first element
///@return On success, the address of the first element. On error, NULL.
SLL_ENTRY *sll_get_first(const SL_LIST *list);

///Retrives the address of the last element
///@return On success, the address of the last element. On error, NULL.
SLL_ENTRY *sll_get_last(const SL_LIST *list);

///Retrives the size of the list
///@return On success, a number greater or equal to 0. On error, -1.
int sll_get_size(const SL_LIST *list);

///Tests if an entry is in the list
///@param list The list to search into
///@param entry The entry we want to test is in the list
///@param prev_entry If the entry is found this parameter can store the previous element
///@return true if the entry is found in the list, false otherwise
bool sll_search_entry(SL_LIST *list, SLL_ENTRY *entry, SLL_ENTRY **prev_entry);

///Inserts the entry as the first element in the list
///@param list The list in which the element is inserted
///@param entry The entry for the element
void sll_insert_first(SL_LIST *list, SLL_ENTRY *entry);

///Inserts the entry as the last element in the list
///@param list The list in which the element is inserted
///@param entry The entry for the element
void sll_insert_last(SL_LIST *list, SLL_ENTRY *entry);

///Inserts a new element before a given entry
///@param list The list in which the element is inserted
///@param entry The new element to insert
///@param before_entry The entry that will be used as reference
void sll_insert_before(SL_LIST *list, SLL_ENTRY *entry, SLL_ENTRY *before_entry);

///Inserts a new element after a given entry
///@param list The list in which the element is inserted
///@param entry The new element to insert
///@param after_entry The entry that will be used as reference
void sll_insert_after(SL_LIST *list, SLL_ENTRY *entry, SLL_ENTRY *after_entry);

///Removes the first entry in the list
///@param list The list from which to remove the element
///@return On success the address of the removed entry is returned. On error, NULL.
SLL_ENTRY *sll_remove_first(SL_LIST *list);

///Removes the last entry in the list
///@param list The list from which to remove the element
///@return On success the address of the removed entry is returned. On error, NULL.
SLL_ENTRY *sll_remove_last(SL_LIST *list);

///Removes the last entry in the list
///@param list The list from which to remove the element
///@param entry The element to remove
///@return On success the address of the removed entry is returned. On error, NULL.
SLL_ENTRY *sll_remove_element(SL_LIST *list, SLL_ENTRY *entry);

#endif //__SINGLE_LINKED_LIST_H__