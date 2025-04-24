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

void deleteAtLast(Node *&head)
{
    if (head == NULL) // If the list is empty, do nothing
        return;
    if (head->next == NULL) // If there's only one node, delete it
    {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL) // Traverse to the second last node
    {
        temp = temp->next;
    }
    delete temp->next; // Delete the last node
    temp->next = NULL; // Set the next of the second last node to NULL
}

int main()
{
    Node *head = new Node(1);
    Node *newNode = new Node(2);
    Node *newNode2 = new Node(3);

    head->next = newNode;
    newNode->next = newNode2;

    // Delete the first node of the linked list
    deleteAtLast(head); // Delete the first node

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