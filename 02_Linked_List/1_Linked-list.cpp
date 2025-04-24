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

int main()
{
    // Node *head = new Node(1);
    //  head->next = new Node(2);
    //  head->next->next = new Node(3);
    //  head->next->next->next = new Node(4);

    Node *head = new Node(1); // Create the first node
                              // cout << head->data << endl; // Output: 1
    Node *newNode = new Node(2);
    head->next = newNode; // Link the first node to the second node

    Node *newNode2 = new Node(3);
    newNode->next = newNode2; // Link the second node to the third node

    // Print the linked list
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Free the allocated memory
    temp = head;
    while (temp != NULL)
    {
        Node *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}