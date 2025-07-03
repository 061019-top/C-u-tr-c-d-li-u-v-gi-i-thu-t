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

void sortList(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* outer;
    Node* inner;
    int temp;

    for (outer = head; outer != NULL; outer = outer->next) {
        for (inner = outer->next; inner != NULL; inner = inner->next) {
            if (outer->value > inner->value) {
                temp = outer->value;
                outer->value = inner->value;
                inner->value = temp;
            }
        }
    }
}

int main() {
    Node* head = createNode(1);
    Node* node2 = createNode(8);
    Node* node3 = createNode(2);
    Node* node4 = createNode(3);
    Node* node5 = createNode(4);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    sortList(head);
    printList(head);

    return 0;
}
