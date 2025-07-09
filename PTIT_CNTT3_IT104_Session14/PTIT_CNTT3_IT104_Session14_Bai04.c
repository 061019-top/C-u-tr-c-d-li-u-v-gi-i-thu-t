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

int isEmpty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s) {
    int value;
    printf("Nhập số: ");
    scanf("%d", &value);

    if (value <= 0) {
        printf("Không hợp lệ\n");
        return;
    }

    Node* node = createNode(value);
    if (!node) return;

    node->next = s->top;
    s->top = node;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Ngăn xếp trống!\n");
        return -1;
    }
    Node* temp = s->top;
    int value = temp->data;
    s->top = temp->next;
    free(temp);
    return value;
}

void prefillStack(Stack* s, int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        Node* node = createNode(arr[i]);
        if (!node) continue;
        node->next = s->top;
        s->top = node;
    }
}

void printStack(Stack* s) {
    if (isEmpty(s)) {
        printf("Ngăn xếp trống!\n");
        return;
    }

    Node* curr = s->top;
    printf("Stack = {\n   ");
    while (curr) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n}\n");
}

void freeStack(Stack* s) {
    Node* curr = s->top;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(s);
}

int main() {
    Stack* s = createStack();
    int arr[] = {1, 2, 3, 4, 5};
    prefillStack(s, arr, 5);

    printf("Trước:\n");
    printStack(s);

    int value = pop(s);
    if (value != -1) {
        printf("Giá trị vừa lấy ra: %d\n", value);
    }

    printf("Sau:\n");
    printStack(s);

    freeStack(s);
    return 0;
}
