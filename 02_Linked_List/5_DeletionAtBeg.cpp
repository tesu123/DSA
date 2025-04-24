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

void deleteAtBeg(Node *&head)
{
    if (head == NULL) // If the list is empty, do nothing
        return;
    Node *temp = head; // Store the current head node
    head = head->next; // Move the head pointer to the next node
    delete temp;       // Delete the old head node
}

int main()
{
    Node *head = new Node(1);
    Node *newNode = new Node(2);
    Node *newNode2 = new Node(3);

    head->next = newNode;
    newNode->next = newNode2;

    // Delete the first node of the linked list
    deleteAtBeg(head); // Delete the first node

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