 #include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    printf("NULL <-> ");
    while (current != NULL) {
        printf("%d <-> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

Node* getNodeAt(Node* head, int index) {
    if (index < 0) return NULL;

    Node* current = head;
    for (int i = 0; i < index && current != NULL; i++) {
        current = current->next;
    }
    return current;
}

int main() {
    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;

    printList(head);

    for (int i = 0; i < 5; i++) {
        Node* found = getNodeAt(head, i);
        if (found != NULL) {
            printf("Node %d: %d\n", i + 1, found->value);
        } else {
            printf("Node %d: Khong ton tai\n", i + 1);
        }
    }

    return 0;
}
