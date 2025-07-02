//
// Created by ADMIN on 7/2/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
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

void insertAtHead(Node** headRef, int value) {
    Node* newNode = createNode(value);
    newNode->next = *headRef;
    *headRef = newNode;
}

int main() {
    Node* head = createNode(1);
    Node* secondNode = createNode(2);
    Node* thirdNode = createNode(3);
    Node* fourthNode = createNode(4);
    Node* fifthNode = createNode(5);

    head->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = fourthNode;
    fourthNode->next = fifthNode;

    printList(head);

    int newValue;
    printf("Nhap so nguyen duong can them vao dau danh sach: ");
    scanf("%d", &newValue);

    insertAtHead(&head, newValue);
    printList(head);

    return 0;
}
