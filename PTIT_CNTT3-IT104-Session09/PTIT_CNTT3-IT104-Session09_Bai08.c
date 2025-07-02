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

void deleteAtPosition(Node** headRef, int position) {
    if (*headRef == NULL || position < 0) {
        printf("Danh sach rong hoac vi tri khong hop le.\n");
        return;
    }

    Node* tempNode = *headRef;

    if (position == 0) {
        *headRef = tempNode->next;
        free(tempNode);
        return;
    }

    Node* previousNode = NULL;
    int currentIndex = 0;

    while (tempNode != NULL && currentIndex < position) {
        previousNode = tempNode;
        tempNode = tempNode->next;
        currentIndex++;
    }

    if (tempNode == NULL) {
        printf("Vi tri vuot qua do dai danh sach.\n");
        return;
    }

    previousNode->next = tempNode->next;
    free(tempNode);
}

int main() {
    Node* head = createNode(1);
    Node* second = createNode(2);
    Node* third = createNode(3);
    Node* fourth = createNode(4);
    Node* fifth = createNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    printList(head);

    int position;
    printf("Nhap vi tri can xoa: ");
    scanf("%d", &position);

    deleteAtPosition(&head, position);
    printList(head);

    return 0;
}
