//
// Created by ADMIN on 7/8/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* elements;
    int top;
    int capacity;
} Stack;

// Khởi tạo stack
Stack createStack(int capacity) {
    Stack stack;
    stack.elements = (int*)malloc(sizeof(int) * capacity);
    if (stack.elements == NULL) {
        printf("Không thể cấp phát bộ nhớ.\n");
        exit(1);
    }
    stack.top = -1;
    stack.capacity = capacity;
    return stack;
}

// Kiểm tra stack đầy
int isFull(Stack stack) {
    return stack.top == stack.capacity - 1;
}

// Thêm phần tử vào stack
void push(Stack* stack, int value) {
    if (isFull(*stack)) {
        printf("Stack đầy, không thể thêm %d\n", value);
        return;
    }
    stack->elements[++stack->top] = value;
}

// In stack
void printStack(Stack stack) {
    printf("Các phần tử trong stack:\n");
    for (int i = 0; i <= stack.top; i++) {
        printf("Phần tử %d: %d\n", i, stack.elements[i]);
    }
    printf("Vị trí top: %d\n", stack.top);
    printf("Dung lượng tối đa: %d\n", stack.capacity);
}

// Giải phóng bộ nhớ
void freeStack(Stack* stack) {
    free(stack->elements);
    stack->elements = NULL;
    stack->top = -1;
    stack->capacity = 0;
}

int main() {
    Stack stack = createStack(5);
    int value;

    printf("Nhập 5 phần tử:\n");
    for (int i = 0; i < 5; i++) {
        printf("Phần tử %d: ", i + 1);
        scanf("%d", &value);
        push(&stack, value);
    }

    printStack(stack);
    freeStack(&stack);

    return 0;
}
