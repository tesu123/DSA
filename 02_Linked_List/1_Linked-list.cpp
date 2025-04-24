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

int main() {
    // Create the first node
    Node* head = createNode(1);
    
    // Create and link the second node
    Node* newNode = createNode(2);
    head->next = newNode;
    
    // Create and link the third node
    Node* newNode2 = createNode(3);
    newNode->next = newNode2;

    // Print the linked list
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
