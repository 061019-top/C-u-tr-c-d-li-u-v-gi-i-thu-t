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
    if (size <= 0) return NULL;

    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) return NULL;

    queue->array = (int*)malloc(size * sizeof(int));
    if (queue->array == NULL) {
        free(queue);
        return NULL;
    }

    queue->size = size;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

int isFull(Queue* queue) {
    return queue->rear == queue->size - 1;
}

int isEmpty(Queue* queue) {
    return queue->rear < queue->front;
}

void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    queue->rear++;
    queue->array[queue->rear] = value;
}

void printQueue(Queue* queue) {
    printf("queue = {\n");
    printf("   array = [");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d", queue->array[i]);
        if (i < queue->rear) printf(", ");
    }
    printf("],\n");
    printf("   front = %d,\n", queue->front);
    printf("   rear = %d,\n", queue->rear);
    printf("   capacity = %d\n", queue->size);
    printf("}\n\n");
}

void freeQueue(Queue* queue) {
    if (queue != NULL) {
        free(queue->array);
        free(queue);
    }
}

int main() {
    int size;
    printf("Nhap kich thuoc cua queue: ");
    scanf("%d", &size);

    Queue* queue = createQueue(size);
    if (queue == NULL) {
        printf("Khong du bo nho!\n");
        return 1;
    }

    int num;
    printf("Nhap so phan tu muon them (<= %d): ", size);
    scanf("%d", &num);
    if (num > size) {
        printf("So luong vuot qua suc chua. Chi nhap %d phan tu.\n", size);
        num = size;
    }

    for (int i = 0; i < num; i++) {
        int value;
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        enqueue(queue, value);
    }

    printQueue(queue);

    if (isEmpty(queue)) {
        printf("Queue rong.\n");
    } else {
        printf("Queue khong rong.\n");
    }

    freeQueue(queue);
    return 0;
}
