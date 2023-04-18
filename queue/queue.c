//
// Created by Dan Domnita on 14.03.2023.
//

#include "queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _QUEUE {
    QUEUE_ENTRY *head;
    QUEUE_ENTRY *tail;
    unsigned int size;
} QUEUE;

QUEUE *create_queue() {
    QUEUE *queue = malloc(sizeof(QUEUE));

    if (queue != NULL) {
        memset(queue, 0, sizeof(QUEUE));
    }

    return queue;
}

void delete_queue(QUEUE **queue) {
    if (queue == NULL) {
        return;
    }

    if (*queue != NULL) {
        free(*queue);
        *queue = NULL;
    }
}

unsigned int queue_get_size(QUEUE *queue) {
    if (queue == NULL) {
        return 0;
    }

    return queue->size;
}

void enqueue(QUEUE *queue, QUEUE_ENTRY *entry) {
    if (queue == NULL || entry == NULL) {
        return;
    }

    if (queue->tail == NULL) {
        queue->head = queue->tail = entry;
    } else {
        queue->tail->next = entry;
        queue->tail = entry;
    }
    queue->size ++;
}

QUEUE_ENTRY *dequeue(QUEUE *queue) {
    QUEUE_ENTRY *entry = NULL;

    do {
        if (queue == NULL) {
            break;
        }

        entry = queue->head;

        if (entry == NULL) {
            break;
        }

        queue->head = entry->next;

        if (queue->tail == entry) {
            queue->tail = NULL;
        }

        queue->size --;
    } while (false);

    return entry;
}

