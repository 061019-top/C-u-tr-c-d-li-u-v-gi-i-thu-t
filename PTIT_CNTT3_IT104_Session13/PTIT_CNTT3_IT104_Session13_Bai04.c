//
// Created by ADMIN on 7/8/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *elements;   // Mảng lưu trữ các phần tử
    int top;         // Vị trí đỉnh stack
    int capacity;    // Dung lượng tối đa
} Stack;

// Khởi tạo stack
Stack createStack(int capacity) {
    Stack stack;
    stack.elements = (int *)malloc(sizeof(int) * capacity);
    if (stack.elements == NULL) {
        printf("Lỗi cấp phát bộ nhớ!\n");
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
void push(Stack *stack, int value) {
    if (isFull(*stack)) {
        printf("Stack đầy, không thể thêm %d\n", value);
        return;
    }
    stack->elements[++stack->top] = value;
}

// Lấy phần tử khỏi stack
int pop(Stack *stack) {
    if (isEmpty(*stack)) {
        printf("Stack rỗng, không thể lấy phần tử\n");
        return -1;
    }
    return stack->elements[stack->top--];
}

// In toàn bộ stack (từ dưới lên)
void printStack(Stack stack) {
    printf("Stack hiện tại: ");
    for (int i = 0; i <= stack.top; i++) {
        printf("%d ", stack.elements[i]);
    }
    printf("\nTop: %d\nCapacity: %d\n", stack.top, stack.capacity);
}

// Xem stack theo chiều từ trên xuống (như ngăn xếp thực tế)
void viewStack(Stack stack) {
    printf("Stack (từ đỉnh xuống):\n");
    for (int i = stack.top; i >= 0; i--) {
        printf("%d\n", stack.elements[i]);
    }
}

// Hàm main
int main() {
    int n = 5;
    Stack stack = createStack(n);
    int value;

    printf("Nhập %d phần tử:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Phần tử %d: ", i + 1);
        scanf("%d", &value);
        push(&stack, value);
    }

    printStack(stack);
    viewStack(stack);

    free(stack.elements);
    return 0;
}
