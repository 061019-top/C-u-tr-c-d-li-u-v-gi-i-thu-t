 #include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Không thể cấp phát bộ nhớ\n");
        exit(1);
    }
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

Node* createDoublyLinkedList(int totalNodes) {
    if (totalNodes <= 0) {
        printf("Số phần tử phải lớn hơn 0\n");
        return NULL;
    }

    Node* head = createNode(totalNodes);
    Node* current = head;

    for (int i = totalNodes - 1; i >= 1; i--) {
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

Node* findMiddleNode(Node* head) {
    if (!head) return NULL;

    int length = 0;
    Node* current = head;
    while (current) {
        length++;
        current = current->next;
    }

    int middleIndex = (length + 1) / 2;
    current = head;
    for (int i = 1; i < middleIndex; i++) {
        current = current->next;
    }

    return current;
}

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = createDoublyLinkedList(8);
    printList(head);

    Node* middle = findMiddleNode(head);
    if (middle) {
        printf("Node giữa: %d\n", middle->value);
    } else {
        printf("Danh sách rỗng!\n");
    }

    freeList(head);
    return 0;
}

