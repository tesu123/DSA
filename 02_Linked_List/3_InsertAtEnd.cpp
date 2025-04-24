#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtEnd(Node *&head, int val)
{
    Node *newNode = new Node(val); // Create a new node with the given value
    if (head == NULL)               // If the list is empty, make the new node the head
    {
        head = newNode;
        return;
    }
    Node *temp = head; // Start from the head
    while (temp->next != NULL) // Traverse to the end of the list
    {
        temp = temp->next;
    }
    temp->next = newNode; // Link the last node to the new node
}

int main()
{
    Node *head = new Node(1);
    Node *newNode = new Node(2);
    Node *newNode2 = new Node(3);

    head->next = newNode;
    newNode->next = newNode2;

    // Insert a new node at the start of the linked list
    insertAtEnd(head, 5); // Insert 0 at the start

    // Print the linked list
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}