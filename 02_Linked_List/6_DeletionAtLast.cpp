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

void deleteAtLast(Node** head) {
    if (*head == NULL) {               // If the list is empty, do nothing
        return;
    }
    if ((*head)->next == NULL) {       // If there's only one node
        free(*head);                   // Free the single node
        *head = NULL;                  // Set head to NULL
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL) { // Traverse to the second last node
        temp = temp->next;
    }
    free(temp->next);                  // Free the last node
    temp->next = NULL;                 // Set the next of second last node to NULL
}

int main() {
    // Create the initial linked list: 1->2->3
    Node* head = createNode(1);
    Node* newNode = createNode(2);
    Node* newNode2 = createNode(3);

    head->next = newNode;
    newNode->next = newNode2;

    // Delete the last node of the linked list
    deleteAtLast(&head);  // Delete the last node (3)

    // Print the linked list (now: 1->2)
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
