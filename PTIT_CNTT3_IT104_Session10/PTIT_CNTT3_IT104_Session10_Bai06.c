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

void findMiddleNode(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    if (length == 0) {
        printf("Danh sach rong\n");
        return;
    }

    int middleIndex = length / 2;
    Node* currentNode = head;
    int position = 1;

    for (int i = 0; i < middleIndex; i++) {
        currentNode = currentNode->next;
        position++;
    }

    printf("Node o giua (vi tri %d): %d\n", position, currentNode->value);
}

int main() {
    Node* head = createNode(5);
    Node* second = createNode(4);
    Node* third = createNode(8);
    Node* fourth = createNode(3);
    Node* fifth = createNode(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    printList(head);
    findMiddleNode(head);

    return 0;
}
