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

void deleteAtBeg(Node** head) {
    if (*head == NULL) {      // If the list is empty, do nothing
        return;
    }
    Node* temp = *head;       // Store the current head node
    *head = (*head)->next;    // Move the head pointer to the next node
    free(temp);               // Free the old head node
}

int main() {
    // Create the initial linked list: 1->2->3
    Node* head = createNode(1);
    Node* newNode = createNode(2);
    Node* newNode2 = createNode(3);

    head->next = newNode;
    newNode->next = newNode2;

    // Delete the first node of the linked list
    deleteAtBeg(&head);  // Delete the first node

    // Print the linked list (now: 2->3)
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Free the remaining allocated memory
    temp = head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
