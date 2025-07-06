#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printList(Node *head) {
    Node *currentNode = head;
    printf("NULL <-> ");
    while (currentNode != NULL) {
        printf("%d <-> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

Node *removeHead(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    Node *tempNode = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(tempNode);
    return head;
}

int main() {
    Node *head = createNode(1);
    Node *second = createNode(2);
    Node *third = createNode(3);
    Node *fourth = createNode(4);
    Node *fifth = createNode(5);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    head = removeHead(head);
    printList(head);

    return 0;
}
