//
// Created by ADMIN on 7/10/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *array;
    int size;
    int front;
    int rear;
} Queue;

Queue* createQueue(int size) {
    if (size <= 0) {
        printf("Kích thước phải lớn hơn 0\n");
        return NULL;
    }

    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Không thể cấp phát bộ nhớ cho queue\n");
        return NULL;
    }

    queue->array = (int*)malloc(size * sizeof(int));
    if (queue->array == NULL) {
        printf("Không thể cấp phát bộ nhớ cho mảng\n");
        free(queue);
        return NULL;
    }

    queue->size = size;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

void freeQueue(Queue* queue) {
    if (queue != NULL) {
        free(queue->array);
        free(queue);
    }
}

int main() {
    int size = 10;
    Queue* queue = createQueue(size);
    if (queue == NULL) {
        return 1;
    }

    printf("Front: %d\n", queue->front);
    printf("Rear: %d\n", queue->rear);
    printf("Max size: %d\n", queue->size);

    freeQueue(queue);
    return 0;
}
