//
// Created by Dan Domnita on 22.04.2023.
//

#ifndef QUEUE_INT_QUEUE_H
#define QUEUE_INT_QUEUE_H

#include "queue.h"

/// Adds an int in the queue
/// @param queue The queue to which an element will be added.
/// @param val The element to be added.
void enqueue_int(QUEUE *queue, int val);

/// Removes an int from the queue.
/// @param queue The queue from which to remove the element.
/// @return The element removed from the queue. If the queue is NULL or empty, INT_MIN is returned.
int dequeue_int(QUEUE *queue);

#endif //QUEUE_INT_QUEUE_H
