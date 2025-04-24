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

void insertAtStart(Node *&head, int val)
{

    Node *newNode = new Node(val); // Create a new node with the given value
    newNode->next = head;          // Link the new node to the current head
    head = newNode;                // Update the head to point to the new node
}

int main()
{
    Node *head = new Node(1);
    Node *newNode = new Node(2);
    head->next = newNode;

    Node *newNode2 = new Node(3);
    newNode->next = newNode2;

    // Insert a new node at the start of the linked list
    insertAtStart(head, 4); // Insert 0 at the start

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