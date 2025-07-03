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

void deleteByValue(Node** head, int target) {
    Node* currentNode = *head;

    // Xóa các node đầu tiên có giá trị bằng target
    while (currentNode != NULL && currentNode->value == target) {
        Node* temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
    *head = currentNode;
    if (currentNode == NULL) {
        return;
    }

    Node* prevNode = currentNode;
    currentNode = currentNode->next;

    while (currentNode != NULL) {
        if (currentNode->value == target) {
            Node* temp = currentNode;
            prevNode->next = currentNode->next;
            currentNode = currentNode->next;
            free(temp);
        } else {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
    }
}

int main() {
    Node* head = createNode(5);
    Node* second = createNode(4);
    Node* third = createNode(5);
    Node* fourth = createNode(2);
    Node* fifth = createNode(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    printList(head);

    int targetValue;
    printf("Nhap so nguyen can xoa: ");
    scanf("%d", &targetValue);

    deleteByValue(&head, targetValue);
    printList(head);

    return 0;
}
