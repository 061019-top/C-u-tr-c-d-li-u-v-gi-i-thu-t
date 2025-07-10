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

// Tạo hàng đợi mới
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Khong the cap phat bo nho cho queue!\n");
        return NULL;
    }

    queue->array = (int*)malloc(size * sizeof(int));
    if (queue->array == NULL) {
        free(queue);
        printf("Khong the cap phat bo nho cho mang!\n");
        return NULL;
    }

    queue->size = size;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

// Kiểm tra đầy
int isFull(Queue* queue) {
    return queue->rear == queue->size - 1;
}

// Kiểm tra rỗng
int isEmpty(Queue* queue) {
    return queue->rear < queue->front;
}

// Thêm phần tử vào queue
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    queue->rear++;
    queue->array[queue->rear] = value;
}

// In thông tin queue
void printQueue(Queue* queue) {
    printf("\nqueue = {\n");
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

// In các phần tử trong hàng đợi
void viewQueueElements(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Cac phan tu trong queue:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d\n", queue->array[i]);
    }
}

// Kiểm tra dãy có tăng đều 1 đơn vị
int isIncreasingByOne(Queue* queue) {
    if (isEmpty(queue)) return 0;

    for (int i = queue->front; i < queue->rear; i++) {
        if (queue->array[i + 1] - queue->array[i] != 1) {
            return 0;
        }
    }
    return 1;
}

// Giải phóng bộ nhớ
void freeQueue(Queue* queue) {
    if (queue != NULL) {
        free(queue->array);
        free(queue);
    }
}

// Hàm chính
int main() {
    int size;
    printf("Nhap kich thuoc cua queue: ");
    scanf("%d", &size);

    Queue* queue = createQueue(size);
    if (queue == NULL) return 1;

    int num;
    printf("Nhap so phan tu muon them (<= %d): ", size);
    scanf("%d", &num);
    if (num > size) num = size;

    for (int i = 0; i < num; i++) {
        int value;
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        enqueue(queue, value);
    }

    printQueue(queue);
    viewQueueElements(queue);

    printf("\nKet qua kiem tra tang dan dung 1 don vi:\n");
    if (isIncreasingByOne(queue)) {
        printf("=> Dung: cac phan tu tang dan 1 don vi.\n");
    } else {
        printf("=> Sai: day KHONG tang dan 1 don vi.\n");
    }

    freeQueue(queue);
    return 0;
}
