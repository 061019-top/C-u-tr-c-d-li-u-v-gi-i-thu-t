//
// Created by ADMIN on 7/3/2025.
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

void deleteLastNode(Node** head) {
    if (*head == NULL) return;

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node* currentNode = *head;
    while (currentNode->next->next != NULL) {
        currentNode = currentNode->next;
    }

    free(currentNode->next);
    currentNode->next = NULL;
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

    deleteLastNode(&head);
    printList(head);

    return 0;
}
