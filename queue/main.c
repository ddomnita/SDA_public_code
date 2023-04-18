#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

typedef struct {
    int x;
    int y;
    QUEUE_ENTRY qentry;
}POINT_2D;

typedef struct {
    int x;
    int y;
    int z;
    QUEUE_ENTRY qentry;
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
    QUEUE_ENTRY *entry = NULL;
    POINT_2D *point = NULL;

    const int MAX_POINTS = 10;

    queue = create_queue();
    if (queue == NULL) {
        perror("ERROR creating queue\n");
        return -1;
    }

    printf("Initial size: %d\n", queue_get_size(queue));

    for (int i = 0; i < MAX_POINTS; i++) {
        point = create_point_2d(i, i);

        enqueue(queue, &point->qentry);
    }

    printf("After enqueue size: %d\n", queue_get_size(queue));

    for (int i = 0; i < MAX_POINTS; i++) {
        entry = dequeue(queue);
        if (entry != NULL) {
            point = CONTAINING_RECORD(entry, POINT_2D, qentry);

            printf("(%d, %d) ", point->x, point->y);

            free(point); // we created the point, we have to free it
        }
    }

    delete_queue(&queue);

    return 0;
}
