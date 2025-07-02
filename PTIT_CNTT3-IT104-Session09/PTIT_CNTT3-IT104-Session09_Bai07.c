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

void insertAtPosition(Node** headRef, int value, int position) {
    Node* newNode = createNode(value);

    if (position == 0 || *headRef == NULL) {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }

    Node* currentNode = *headRef;
    int currentIndex = 0;

    while (currentNode != NULL && currentIndex < position - 1) {
        currentNode = currentNode->next;
        currentIndex++;
    }

    if (currentNode != NULL) {
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    } else {
        printf("Khong chen duoc vi tri %d\n", position);
        free(newNode);
    }
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

    int newValue, position;
    printf("Nhap gia tri can chen: ");
    scanf("%d", &newValue);
    printf("Nhap vi tri can chen (bat dau tu 0): ");
    scanf("%d", &position);

    insertAtPosition(&head, newValue, position);
    printList(head);

    return 0;
}
