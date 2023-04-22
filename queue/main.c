#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "int_queue.h"

typedef struct {
    int x;
    int y;
    QUEUE_ENTRY q_entry;
}POINT_2D;

typedef struct {
    int x;
    int y;
    int z;
    QUEUE_ENTRY q_entry;
}POINT_3D;               // This structure can use the same functions as POINT_2D for operating a QUEUE

POINT_2D *create_point_2d(int x, int y) {
    POINT_2D *point = (POINT_2D*)malloc(sizeof(POINT_2D));

    if (point != NULL) {
        memset(point, 0, sizeof(POINT_2D));

        point->x = x;
        point->y = y;
    }

    return point;
}

int main() {
    QUEUE *queue = NULL;
    QUEUE *int_queue = NULL;
    QUEUE_ENTRY *entry = NULL;
    POINT_2D *point = NULL;

    const int MAX_ENTRIES = 10;

    printf("Testing QUEUE:\n");

    queue = create_queue();
    if (queue == NULL) {
        printf("ERROR creating queue\n");
        return -1;
    }

    printf("Initial size: %d\n", queue_get_size(queue));

    for (int i = 0; i < MAX_ENTRIES; i++) {
        point = create_point_2d(i, i);

        enqueue(queue, &point->q_entry);
    }

    printf("After enqueue size: %d\n", queue_get_size(queue));

    for (int i = 0; i < MAX_ENTRIES; i++) {
        entry = dequeue(queue);
        if (entry != NULL) {
            point = CONTAINING_RECORD(entry, POINT_2D, q_entry);

            printf("(%d, %d) ", point->x, point->y);

            free(point); // we created the point, we have to free it
        }
    }

    delete_queue(&queue);

    printf("\n\nTesting int QUEUE:\n");

    int_queue = create_queue();
    if (int_queue == NULL) {
        printf("ERROR creating queue\n");
        return -1;
    }

    for (int i = 0; i < MAX_ENTRIES; i++) {
        enqueue_int(int_queue, i);
    }

    for (int i = 0; i < MAX_ENTRIES; i++) {
        printf("%d ", dequeue_int(int_queue));
    }

    delete_queue(&int_queue);

    return 0;
}
