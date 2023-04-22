//
// Created by Dan Domnita on 14.03.2023.
//

#ifndef SDA_QUEUE_H__
#define SDA_QUEUE_H__

#ifndef CONTAINING_RECORD
#define CONTAINING_RECORD(address, type, field) (\
    (type *)((char*)(address) -(size_t)(&((type *)0)->field)))
#endif

typedef struct QUEUE_ENTRY_STR {
    struct QUEUE_ENTRY_STR *next;
}QUEUE_ENTRY;

typedef struct QUEUE_STR QUEUE;

/// Create a structure of type queue
/// @return A pointer to a structure of type QUEUE. NULL will be return in case of error.
QUEUE *create_queue();

/// It will free the structure created by create_queue function.
/// @param queue A double pointer to a structure of type QUEUE. After the call it is guaranteed that the pointer will be NULL.
void delete_queue(QUEUE **queue);

/// Retrieves the size of a queue.
/// @param queue The queue for which the size is needed.
/// @return The size of the queue.
unsigned int queue_get_size(QUEUE *queue);

/// Adds an entry in the queue
/// @param queue The queue to which an element will be added.
/// @param entry The element to be added.
void enqueue(QUEUE *queue, QUEUE_ENTRY *entry);

/// Removes an element from the queue.
/// @param queue The queue from which to remove the element.
/// @return The element removed from the queue.
QUEUE_ENTRY *dequeue(QUEUE *queue);

#endif //SDA_QUEUE_H__
