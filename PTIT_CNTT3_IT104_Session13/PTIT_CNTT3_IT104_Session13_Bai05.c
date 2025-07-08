//
// Created by ADMIN on 7/8/2025.
//
#include <stdio.h>
#define MAX 100

// Định nghĩa cấu trúc stack dùng mảng
typedef struct {
    int data[MAX];
    int top;
} Stack;

// Khởi tạo stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Kiểm tra stack đầy
int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

// Kiểm tra stack rỗng
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Đẩy phần tử vào stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack đầy!\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// Lấy phần tử khỏi stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack rỗng!\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// In mảng
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Hàm đảo ngược mảng dùng stack
void reverseArray(int array[], int size) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < size; i++) {
        push(&stack, array[i]);
    }

    for (int i = 0; i < size; i++) {
        array[i] = pop(&stack);
    }
}

// Hàm main
int main() {
    int size;

    printf("Nhập số phần tử của mảng (tối đa %d): ", MAX);
    scanf("%d", &size);

    if (size <= 0 || size > MAX) {
        printf("Kích thước không hợp lệ.\n");
        return 1;
    }

    int array[size];
    for (int i = 0; i < size; i++) {
        printf("Phần tử %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Mảng ban đầu: ");
    printArray(array, size);

    reverseArray(array, size);

    printf("Mảng sau khi đảo ngược: ");
    printArray(array, size);

    return 0;
}
