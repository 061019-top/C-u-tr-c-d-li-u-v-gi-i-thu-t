 #include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Không thể cấp phát bộ nhớ\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* createList(int count) {
    if (count <= 0) {
        printf("Số phần tử phải lớn hơn 0\n");
        return NULL;
    }

    Node* head = createNode(count);
    Node* current = head;

    for (int i = count - 1; i >= 1; i--) {
        Node* newNode = createNode(i);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    return head;
}

void printList(Node* head) {
    Node* current = head;
    printf("Danh sách: ");
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void append(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = createList(5);
    printList(head);

    int value;
    printf("Nhập số nguyên dương để thêm vào cuối danh sách: ");
    scanf("%d", &value);

    if (value <= 0) {
        printf("Vui lòng nhập số nguyên dương!\n");
    } else {
        append(&head, value);
        printList(head);
    }

    freeList(head);
    return 0;
}
