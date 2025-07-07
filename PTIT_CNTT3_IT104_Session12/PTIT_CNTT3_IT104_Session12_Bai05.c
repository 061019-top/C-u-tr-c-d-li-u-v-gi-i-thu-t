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

void deleteNodeByValue(Node** head, int target) {
    if (*head == NULL) return;

    Node* current = *head;
    while (current != NULL) {
        if (current->value == target) {
            Node* temp = current;

            if (current == *head) {
                *head = current->next;
                if (*head) (*head)->prev = NULL;
            } else {
                if (current->prev) current->prev->next = current->next;
                if (current->next) current->next->prev = current->prev;
            }

            current = current->next;
            free(temp);
        } else {
            current = current->next;
        }
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

    int target;
    printf("Nhập số cần xóa: ");
    scanf("%d", &target);

    if (target <= 0) {
        printf("Vui lòng nhập số nguyên dương!\n");
    } else {
        deleteNodeByValue(&head, target);
        printList(head);
    }

    freeList(head);
    return 0;
}

