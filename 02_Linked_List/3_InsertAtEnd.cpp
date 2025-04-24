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

void insertAtEnd(Node** head, int val) {
    Node* newNode = createNode(val);  // Create a new node with the given value
    if (*head == NULL) {              // If the list is empty, make the new node the head
        *head = newNode;
        return;
    }
    Node* temp = *head;              // Start from the head
    while (temp->next != NULL) {     // Traverse to the end of the list
        temp = temp->next;
    }
    temp->next = newNode;            // Link the last node to the new node
}

int main() {
    // Create the initial linked list: 1->2->3
    Node* head = createNode(1);
    Node* newNode = createNode(2);
    Node* newNode2 = createNode(3);

    head->next = newNode;
    newNode->next = newNode2;

    // Insert a new node at the end of the linked list
    insertAtEnd(&head, 5);  // Insert 5 at the end

    // Print the linked list (now: 1->2->3->5)
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
