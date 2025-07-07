 #include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Không thể cấp phát bộ nhớ\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* createDoublyLinkedList(int count) {
    if (count <= 0) {
        printf("Số phần tử phải lớn hơn 0\n");
        return NULL;
    }

    Node* head = createNode(count);
    Node* current = head;

    for (int i = count - 1; i >= 1; i--) {
        Node* newNode = createNode(i);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    return head;
}

void printList(Node* head) {
    printf("Danh sách liên kết đôi: ");
    for (Node* current = head; current != NULL; current = current->next) {
        printf("%d ", current->value);
    }
    printf("\n");
}

void deleteLastNode(Node** head) {
    if (*head == NULL) return;

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev == NULL) {
        free(current);
        *head = NULL;
    } else {
        current->prev->next = NULL;
        free(current);
    }
}

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = createDoublyLinkedList(5);
    printList(head);

    deleteLastNode(&head);
    printList(head);

    freeList(head);
    return 0;
}

