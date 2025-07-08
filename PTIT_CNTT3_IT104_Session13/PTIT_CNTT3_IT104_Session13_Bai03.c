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

// Tạo stack mới
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

// Kiểm tra stack rỗng
int isEmpty(Stack stack) {
    return stack.top == -1;
}

// Đẩy phần tử vào stack
void push(Stack* stack, int value) {
    if (isFull(*stack)) {
        printf("Stack đầy.\n");
        return;
    }
    stack->elements[++stack->top] = value;
}

// Lấy phần tử khỏi stack
int pop(Stack* stack) {
    if (isEmpty(*stack)) {
        printf("Stack rỗng.\n");
        return -1;
    }
    return stack->elements[stack->top--];
}

// In stack
void printStack(Stack stack) {
    if (isEmpty(stack)) {
        printf("Stack hiện rỗng.\n");
        return;
    }
    printf("Các phần tử trong stack: ");
    for (int i = 0; i <= stack.top; i++) {
        printf("%d ", stack.elements[i]);
    }
    printf("\nTop hiện tại: %d\n", stack.top);
    printf("Dung lượng tối đa: %d\n", stack.capacity);
}

// Giải phóng bộ nhớ
void freeStack(Stack* stack) {
    free(stack->elements);
    stack->elements = NULL;
    stack->top = -1;
    stack->capacity = 0;
}

// Hàm main
int main() {
    Stack stack = createStack(5);
    int value;

    printf("Nhập 5 phần tử vào stack:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &value);
        push(&stack, value);
    }

    printStack(stack);

    int popped = pop(&stack);
    if (popped != -1) {
        printf("Đã lấy ra: %d\n", popped);
    }

    // Xóa toàn bộ phần tử
    while (!isEmpty(stack)) {
        pop(&stack);
    }

    printStack(stack);
    pop(&stack);  // Gọi pop khi stack rỗng để kiểm tra
    freeStack(&stack);

    return 0;
}
