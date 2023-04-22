//
// Created by Dan Domnita on 22.04.2023.
//

#include "int_queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int data;
    QUEUE_ENTRY q_entry;
}QUEUE_INT_NODE;

QUEUE_INT_NODE *create_q_node(int val) {
    QUEUE_INT_NODE *node = (QUEUE_INT_NODE *) malloc(sizeof(QUEUE_INT_NODE));

    if (node != NULL) {
        memset(node, 0, sizeof(QUEUE_INT_NODE));

        node->data = val;
    }

    return node;
}

void enqueue_int(QUEUE *queue, int val) {
    if (queue == NULL) {
        return;
    }

    QUEUE_INT_NODE *node = create_q_node(val);

    if (node != NULL) {
        enqueue(queue, &node->q_entry);
    }
}

int dequeue_int(QUEUE *queue) {
    QUEUE_INT_NODE *node = NULL;
    QUEUE_ENTRY *entry = dequeue(queue);
    int val = INT_MIN;

    do {
        if (entry == NULL) {
            break;
        }

        node = CONTAINING_RECORD(entry, QUEUE_INT_NODE, q_entry);
        val = node->data;

        free(node);
    } while (false);

    return val;
}

