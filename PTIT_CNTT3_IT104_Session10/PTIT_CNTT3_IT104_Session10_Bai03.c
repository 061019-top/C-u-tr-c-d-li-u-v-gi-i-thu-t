//
// Created by ADMIN on 7/3/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->value);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

// Thêm phần tử vào cuối danh sách
void appendNode(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* currentNode = *head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

int main() {
    Node* head = createNode(5);
    Node* second = createNode(4);
    Node* third = createNode(3);
    Node* fourth = createNode(2);
    Node* fifth = createNode(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    printList(head);

    int newValue;
    printf("Nhap so nguyen can them: ");
    scanf("%d", &newValue);

    appendNode(&head, newValue);
    printList(head);

    return 0;
}
