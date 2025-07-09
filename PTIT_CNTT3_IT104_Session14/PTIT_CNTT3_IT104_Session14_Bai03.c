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
    if (!node) {
        printf("Không thể cấp phát bộ nhớ!\n");
        return NULL;
    }
    node->data = value;
    node->next = NULL;
    return node;
}

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (!s) {
        printf("Không thể cấp phát bộ nhớ!\n");
        return NULL;
    }
    s->top = NULL;
    return s;
}

void push(Stack* s) {
    int value;
    printf("Nhập số: ");
    if (scanf("%d", &value) != 1 || value <= 0) {
        printf("Giá trị không hợp lệ!\n");
        while (getchar() != '\n'); // xóa bộ đệm nhập
        return;
    }

    Node* node = createNode(value);
    if (!node) return;

    node->next = s->top;
    s->top = node;
}

void prefill(Stack* s, int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        Node* node = createNode(arr[i]);
        if (!node) continue;
        node->next = s->top;
        s->top = node;
    }
}

void printStack(Stack* s) {
    if (!s->top) {
        printf("Stack trống...\n");
        return;
    }

    printf("Stack từ trên xuống:\n");
    for (Node* cur = s->top; cur != NULL; cur = cur->next) {
        printf("%d\n", cur->data);
    }
}

void freeStack(Stack* s) {
    Node* cur = s->top;
    while (cur) {
        Node* temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(s);
}

int main() {
    Stack* s1 = createStack();
    int arr[] = {1, 2, 3, 4, 5};
    prefill(s1, arr, 5);

    printf("Stack 1:\n");
    printStack(s1);
    push(s1);
    printf("Sau khi push:\n");
    printStack(s1);

    Stack* s2 = createStack();
    printf("\nStack 2:\n");
    printStack(s2);

    freeStack(s1);
    freeStack(s2);
    return 0;
}
