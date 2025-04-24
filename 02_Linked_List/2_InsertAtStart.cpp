#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtStart(Node** head, int val) {
    Node* newNode = createNode(val);  // Create a new node with the given value
    newNode->next = *head;            // Link the new node to the current head
    *head = newNode;                 // Update the head to point to the new node
}

int main() {
    // Create the initial linked list: 1->2->3
    Node* head = createNode(1);
    Node* newNode = createNode(2);
    head->next = newNode;

    Node* newNode2 = createNode(3);
    newNode->next = newNode2;

    // Insert a new node at the start of the linked list
    insertAtStart(&head, 4);  // Insert 4 at the start

    // Print the linked list (now: 4->1->2->3)
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Free the allocated memory
    temp = head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
