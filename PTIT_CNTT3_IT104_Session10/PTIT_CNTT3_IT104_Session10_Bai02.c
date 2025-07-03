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

void printNodeValues(Node* head) {
    int index = 1;
    Node* currentNode = head;
    while (currentNode != NULL) {
        printf("Node %d: %d\n", index, currentNode->value);
        currentNode = currentNode->next;
        index++;
    }
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
    printNodeValues(head);

    return 0;
}
