//
// Created by ADMIN on 7/9/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Không đủ bộ nhớ\n");
        return NULL;
    }
    node->data = value;
    node->next = NULL;
    return node;
}

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Không đủ bộ nhớ\n");
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

void push(Stack* stack) {
    int value;
    printf("Nhập số: ");
    if (scanf("%d", &value) != 1 || value <= 0) {
        printf("Giá trị không hợp lệ\n");
        while (getchar() != '\n'); // Xóa bộ đệm
        return;
    }

    Node* node = createNode(value);
    if (!node) return;

    node->next = stack->top;
    stack->top = node;
}

void printStack(Stack* stack) {
    Node* current = stack->top;
    printf("Stack = {\n   ");
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n}\n");
}

void prefillStack(Stack* stack, int values[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        Node* node = createNode(values[i]);
        if (!node) continue;
        node->next = stack->top;
        stack->top = node;
    }
}

void freeStack(Stack* stack) {
    Node* current = stack->top;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}

int main() {
    Stack* stack = createStack();
    if (!stack) return 1;

    int initialValues[] = {1, 2, 3, 4, 5};
    prefillStack(stack, initialValues, 5);

    printf("Trước khi push:\n");
    printStack(stack);

    push(stack);

    printf("Sau khi push:\n");
    printStack(stack);

    freeStack(stack);
    return 0;
}
