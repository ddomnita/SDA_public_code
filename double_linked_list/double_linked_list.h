//
// Created by Dan Domnita on 20.03.2023.
//

#ifndef SDA_DOUBLE_LINKED_LIST_H__
#define SDA_DOUBLE_LINKED_LIST_H__

#include <stdbool.h>

#ifndef CONTAINING_RECORD
#define CONTAINING_RECORD(address, type, field) (\
    (type *)((char*)(address) -(size_t)(&((type *)0)->field)))
#endif

typedef struct DLL_ENTRY_STR {
    struct DLL_ENTRY_STR *next;
    struct DLL_ENTRY_STR *prev;
}DLL_ENTRY;

typedef struct DL_LIST_STR DL_LIST;

///Creates a new double linked list
///@return On success the address of a new list is returned. On error NULL is returned.
DL_LIST *dll_create_list();

///Frees a double linked list
///@pre The elements in the list have to be removed first.
void dll_delete_list(DL_LIST **list);

///Retrieves the address of the first element
///@return On success, the address of the first element. On error, NULL.
DLL_ENTRY *dll_get_first(DL_LIST *list);

///Retrieves the address of the last element
///@return On success, the address of the last element. On error, NULL.
DLL_ENTRY *dll_get_last(DL_LIST *list);

///Retrieves the size of the list
///@return The size of the list. 0 if the list is NULL.
unsigned int dll_get_size(DL_LIST *list);

///Tests if an entry is in the list
///@param list The list to search into
///@param entry The entry we want to test is in the list
///@return true if the entry is found in the list, false otherwise
bool dll_check_entry_in_list(DL_LIST *list, DLL_ENTRY *entry);

///Inserts the entry as the first element in the list
///@param list The list in which the element is inserted
///@param entry The entry for the element
void dll_insert_first(DL_LIST *list, DLL_ENTRY *entry);

///Inserts the entry as the last element in the list
///@param list The list in which the element is inserted
///@param entry The entry for the element
void dll_insert_last(DL_LIST *list, DLL_ENTRY *entry);

///Inserts a new element before a given entry
///@pre The before_entry must be a member in the given list.
///@param list The list in which the element is inserted
///@param entry The new element to insert
///@param before_entry The entry that will be used as reference
void dll_insert_before(DL_LIST *list, DLL_ENTRY *entry, DLL_ENTRY *before_entry);

///Inserts a new element after a given entry
///@pre The after_entry must be a member in the given list.
///@param list The list in which the element is inserted
///@param entry The new element to insert
///@param after_entry The entry that will be used as reference
void dll_insert_after(DL_LIST *list, DLL_ENTRY *entry, DLL_ENTRY *after_entry);

///Removes the first entry in the list
///@param list The list from which to remove the element
///@return On success the address of the removed entry is returned. On error, NULL.
DLL_ENTRY *dll_remove_first(DL_LIST *list);

///Removes the last entry in the list
///@param list The list from which to remove the element
///@return On success the address of the removed entry is returned. On error, NULL.
DLL_ENTRY *dll_remove_last(DL_LIST *list);

///Removes the entry in the list
///@pre The entry must be a member in the given list.
///@param list The list from which to remove the element
///@param entry The element to remove
///@return On success the address of the removed entry is returned. On error, NULL.
DLL_ENTRY *dll_remove_element(DL_LIST *list, DLL_ENTRY *entry);

#endif //SDA_DOUBLE_LINKED_LIST_H__
