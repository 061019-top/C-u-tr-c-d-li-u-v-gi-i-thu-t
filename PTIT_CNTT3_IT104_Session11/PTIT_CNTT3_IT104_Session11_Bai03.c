#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool searchList(Node* head, int target) {
    Node* current = head;
    while (current != NULL) {
        if (current->value == target) {
            return true;
        }
        current = current->next;
    }
    return false;
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

    int input;
    printf("Nhap so nguyen duong ban muon tim: ");
    scanf("%d", &input);

    if (searchList(head, input)) {
        printf("Phan tu %d co trong danh sach.\n", input);
    } else {
        printf("Phan tu %d khong co trong danh sach.\n", input);
    }

    return 0;
}
