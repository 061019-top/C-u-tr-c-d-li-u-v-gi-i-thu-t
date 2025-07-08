//
// Created by ADMIN on 7/8/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* elements;   // Mảng chứa phần tử stack
    int top;         // Chỉ số phần tử đầu
    int capacity;    // Sức chứa tối đa
} Stack;

// Hàm tạo stack
Stack createStack(int capacity) {
    Stack stack;
    stack.elements = (int*)malloc(sizeof(int) * capacity);
    if (stack.elements == NULL) {
        printf("Không thể cấp phát bộ nhớ\n");
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
        printf("Ngăn xếp đầy, không thể thêm %d\n", value);
        return;
    }
    stack->elements[++stack->top] = value;
}

// In stack
void printStack(Stack stack) {
    printf("Stack (top -> bottom): ");
    for (int i = stack.top; i >= 0; i--) {
        printf("%d ", stack.elements[i]);
    }
    printf("\n");
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

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    printStack(stack);

    freeStack(&stack);

    return 0;
}
