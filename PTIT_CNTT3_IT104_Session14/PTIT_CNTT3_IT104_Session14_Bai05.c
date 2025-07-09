//
// Created by ADMIN on 7/9/2025.
//
#include <stdio.h>
#include <stdlib.h>

// Cấu trúc Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Cấu trúc Stack
typedef struct Stack {
    Node* top;
} Stack;

// Hàm khởi tạo stack
void initStack(Stack* stack) {
    stack->top = NULL;
}

// Hàm tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Không thể cấp phát bộ nhớ\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Hàm đẩy phần tử vào stack
void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    if (newNode == NULL) return;
    newNode->next = stack->top;
    stack->top = newNode;
}

// ✅ Hàm xem phần tử đầu ngăn xếp
int xemPhanTuDau(Stack stack) {
    if (stack.top == NULL) {
        printf("Ngăn xếp trống\n");
        return -1;
    }
    return stack.top->data;
}

// Hàm giải phóng bộ nhớ stack
void freeStack(Stack* stack) {
    Node* temp;
    while (stack->top != NULL) {
        temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
}

// Hàm main để test
int main() {
    Stack stack;
    initStack(&stack);

    // Test 1: Ngăn xếp có phần tử
    push(&stack, 5);
    push(&stack, 4);
    push(&stack, 3);
    push(&stack, 2);
    push(&stack, 1);

    int topValue = xemPhanTuDau(stack);
    if (topValue != -1)
        printf("Phần tử đầu ngăn xếp là: %d\n", topValue);

    freeStack(&stack);

    // Test 2: Ngăn xếp trống
    Stack emptyStack;
    initStack(&emptyStack);
    topValue = xemPhanTuDau(emptyStack);
    if (topValue != -1)
        printf("Phần tử đầu ngăn xếp là: %d\n", topValue);

    return 0;
}
