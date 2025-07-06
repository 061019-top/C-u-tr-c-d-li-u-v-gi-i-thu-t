#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void printList(Node *head) {
    Node *current = head;
    printf("NULL <-> ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node *insertHead(Node *head, int data) {
    Node *newNode = createNode(data);
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    newNode->prev = NULL; // cần gán lại prev của node đầu
    return newNode;
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

    head = insertHead(head, 7);

    printList(head);

    return 0;
}

