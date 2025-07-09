//
// Created by ADMIN on 7/9/2025.
//
#include <stdio.h>
#include <stdlib.h>

// Node trong stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Cấu trúc ngăn xếp
typedef struct Stack {
    Node* top;
} Stack;

// Tạo node mới
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Không đủ bộ nhớ!\n");
        return NULL;
    }
    node->data = value;
    node->next = NULL;
    return node;
}

// Tạo ngăn xếp mới
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Không đủ bộ nhớ!\n");
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

// Kiểm tra stack rỗng
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Đẩy phần tử vào stack
void push(Stack* stack, int value) {
    Node* node = createNode(value);
    if (node == NULL) return;

    node->next = stack->top;
    stack->top = node;
}

// Giải phóng bộ nhớ của stack
void freeStack(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}

// In stack từ top -> bottom
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack rỗng.\n");
        return;
    }

    Node* current = stack->top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Hàm main kiểm tra
int main() {
    Stack* stack = createStack();
    if (stack == NULL) return 1;

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printStack(stack);  // Expected: 30 20 10

    freeStack(stack);
    return 0;
}
