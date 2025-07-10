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

// Tạo queue mới
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Khong the cap phat bo nho!\n");
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

// Kiểm tra queue đầy
int isFull(Queue* queue) {
    return queue->rear == queue->size - 1;
}

// Kiểm tra queue rỗng
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

// In toàn bộ queue
void printQueue(Queue* queue) {
    printf("\n== Cấu trúc queue ==\n");
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
    printf("}\n");
}

// Hiển thị các phần tử hàng đợi theo dòng
void viewQueueElements(Queue* queue) {
    printf("\n== Các phần tử trong queue ==\n");
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d\n", queue->array[i]);
    }
}

// Giải phóng bộ nhớ
void freeQueue(Queue* queue) {
    if (queue != NULL) {
        free(queue->array);
        free(queue);
    }
}

// Hàm main
int main() {
    int size;
    printf("Nhap kich thuoc cua queue: ");
    scanf("%d", &size);

    Queue* queue = createQueue(size);
    if (queue == NULL) {
        return 1;
    }

    int num;
    printf("Nhap so phan tu muon them (<= %d): ", size);
    scanf("%d", &num);
    if (num > size) {
        num = size;
    }

    for (int i = 0; i < num; i++) {
        int value;
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        enqueue(queue, value);
    }

    printQueue(queue);
    viewQueueElements(queue);

    if (isEmpty(queue)) {
        printf("\nQueue dang trong!\n");
    } else {
        printf("\nQueue KHONG trong!\n");
    }

    freeQueue(queue);
    return 0;
}
