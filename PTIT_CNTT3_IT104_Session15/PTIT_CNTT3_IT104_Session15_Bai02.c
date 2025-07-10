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

void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    queue->rear++;
    queue->array[queue->rear] = value;
    printQueue(queue);
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

    int value;
    for (int i = 0; i < size; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        enqueue(queue, value);
    }

    freeQueue(queue);
    return 0;
}
