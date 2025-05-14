#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *head2 = NULL;

void createNode(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void createNode2(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if (head2 == NULL)
    {
        head2 = newNode;
    }
    else
    {
        struct node *temp = head2;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtFront(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;

    // alternate way
    // struct node *temp = head;
    // head = newNode;
    // head->next = temp;
}

void insertAtEnd(int val)
{
    createNode(val);
}

void insertAtKthPos(int val, int pos)
{

    if (pos == 1)
    {
        insertAtFront(val);
        return;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    pos--;
    struct node *ptr = head;

    while (pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void insertAfterKthNode(int val, int pos)
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    struct node *ptr = head;

    while (pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void insertBeforeKthNode(int val, int pos)
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    pos -= 2;
    struct node *ptr = head;

    while (pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void insertAfterNodeVal(int nodeVal, int newVal)
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = newVal;
    newNode->next = NULL;

    struct node *ptr = head;

    while (ptr->data != nodeVal)
    {
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void insertBeforeNodeVal(int nodeVal, int newVal)
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = newVal;
    newNode->next = NULL;

    if (head->data == nodeVal)
    {
        insertAtFront(newVal);
        return;
    }
    struct node *ptr = head;

    while (ptr->next->data != nodeVal)
    {
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void deleteFirst()
{
    if (head == NULL)
    {
        printf("\nList is already empty!");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
}

void deleteLast()
{
    if (head == NULL)
    {
        printf("List is already empty!");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        struct node *temp2 = head;

        while (temp->next != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        free(temp);
        temp = NULL;
    }
}

void del_pos(struct node **head, int pos)
{
    struct node *current = *head;
    struct node *previous = *head;

    if (*head == NULL)
    {
        printf("List is already empty!");
    }
    else if (pos == 1)
    {
        *head = current->next;
        free(current);
        current = NULL;
    }
    else
    {

        while (pos != 1)
        {
            previous = current;
            current = current->next;
            pos--;
        }
        previous->next = current->next;
        free(current);
        current = NULL;
    }
}

// ----------------------------------------------------
void deleteAfterKthNode(int pos)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct node *ptr = head;
    while (pos != 1 && ptr != NULL)
    {
        ptr = ptr->next;
        pos--;
    }
    if (ptr == NULL || ptr->next == NULL)
    {
        printf("No node after position %d to delete!\n", pos);
        return;
    }
    struct node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
}

void deleteBeforeKthNode(int pos)
{
    if (pos <= 1 || head == NULL || head->next == NULL)
    {
        printf("No node before position %d to delete!\n", pos);
        return;
    }

    if (pos == 2)
    {
        deleteFirst();
        return;
    }

    struct node *ptr = head;
    struct node *prev = NULL;
    struct node *prev_prev = NULL;

    pos -= 2;
    while (pos != 1 && ptr != NULL)
    {
        prev_prev = prev;
        prev = ptr;
        ptr = ptr->next;
        pos--;
    }
    if (ptr == NULL)
    {
        printf("Position out of range!\n");
        return;
    }
    prev_prev->next = ptr;
    free(prev);
}

void deleteNodeWithValue(int val)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if (head->data == val)
    {
        deleteFirst();
        return;
    }

    struct node *ptr = head;
    struct node *prev = NULL;

    while (ptr != NULL && ptr->data != val)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Node with value %d not found!\n", val);
        return;
    }
    prev->next = ptr->next;
    free(ptr);
}

void reverseList()
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void sortList()
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
// -----------------------------------------------------------

void searchElement(int val)
{
    if (head == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    int pos = 1;
    struct node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == val)
        {
            printf("\nElement found at %d position\n", pos);
            return;
        }
        pos++;
        temp = temp->next;
    }

    if (temp->data == val)
    {
        printf("\nElement found at %d position\n", pos);
    }
    else
    {
        printf("\nElement not found!\n");
    }
}

// -----------------------------------------------------
struct node *mergeSortedLists(struct node *a, struct node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    struct node *result = NULL;

    if (a->data <= b->data)
    {
        result = a;
        result->next = mergeSortedLists(a->next, b);
    }
    else
    {
        result = b;
        result->next = mergeSortedLists(a, b->next);
    }
    return result;
}

void mergeTwoLists()
{
    if (head == NULL || head2 == NULL)
    {
        printf("Both lists must be non-empty to merge!\n");
        return;
    }

    // Check if lists are sorted
    struct node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data > temp->next->data)
        {
            printf("First list is not sorted in ascending order!\n");
            return;
        }
        temp = temp->next;
    }

    temp = head2;
    while (temp->next != NULL)
    {
        if (temp->data > temp->next->data)
        {
            printf("Second list is not sorted in ascending order!\n");
            return;
        }
        temp = temp->next;
    }

    head = mergeSortedLists(head, head2);
    head2 = NULL;
    printf("Lists merged successfully!\n");
}

void concatenateLists()
{
    if (head == NULL)
    {
        head = head2;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head2;
    }
    head2 = NULL;
    printf("Lists concatenated successfully!\n");
}

bool areListsEqual(struct node *a, struct node *b)
{
    while (a != NULL && b != NULL)
    {
        if (a->data != b->data)
            return false;
        a = a->next;
        b = b->next;
    }
    return (a == NULL && b == NULL);
}

void createSecondList()
{
    if (head2 != NULL)
    {
        printf("Second list already exists!\n");
        return;
    }

    int size, value;
    printf("\nEnter the number of nodes in second list: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter value of %d node: ", i + 1);
        scanf("%d", &value);
        createNode2(value);
    }
    printf("\nSecond linked list created successfully!\n");
}
// ----------------------------------------------------

void displayList(struct node *head)
{
    if (head == NULL)
    {
        printf("\nList is empty!");
        return;
    }
    printf("\nThe list: ");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf(" %d ->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}

int main()
{
    int choice, size, value, k, nodeVal, newVal;

    while (1)
    {
        printf("\n_____________MENU_____________\n");
        printf("\n1. Create linked list");
        printf("\n2. Display the list");
        printf("\n3. Insert an element at the front of the list ");
        printf("\n4. Insert an element at the end of the list ");
        printf("\n5. Insert a node after the kth node");
        printf("\n6. Insert a node after the node containing a given value: ");
        printf("\n7. Insert a node before kth node");
        printf("\n8. Insert a node before the node containing a given value: ");
        printf("\n9. Delete the first node");
        printf("\n10. Delete the last node");
        printf("\n11. Delete a node after the kth node");
        printf("\n12. Delete a node before the kth node.");
        printf("\n13. Delete the kth node");
        printf("\n14. Delete the node containing a specified value");
        printf("\n15. Find the reverse of a list");
        printf("\n16. Sort the list");
        printf("\n17. Search a given element ");
        printf("\n18. Merge two lists; those are in ascending order");
        printf("\n19. Concatenate two list ");
        printf("\n20. Find if two lists are equal(Boolean output)");
        printf("\n21. Exit");
        printf("\nEnter your choice -> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the number of nodes in list: ");
            scanf("%d", &size);
            for (int i = 0; i < size; i++)
            {
                printf("Enter value of %d node: ", i + 1);
                scanf("%d", &value);
                createNode(value);
            }
            printf("\nLinked list created successfully!\n");
            break;

        case 2:
            displayList(head);
            break;

        case 3:
            printf("\nEnter value: ");
            scanf("%d", &value);
            insertAtFront(value);
            printf("\nValue added at front successfully!\n");
            break;

        case 4:
            printf("\nEnter value: ");
            scanf("%d", &value);
            insertAtEnd(value);
            printf("\nValue added at end successfully!\n");
            break;

        case 5:
            printf("\nEnter value: ");
            scanf("%d", &value);
            printf("\nEnter position: ");
            scanf("%d", &k);
            insertAfterKthNode(value, k);
            printf("\nNode added after %dth node successfully!\n", k);
            break;

        case 6:
            printf("\nEnter value of node after which new node to be inserted: ");
            scanf("%d", &nodeVal);
            printf("\nEnter new node value: ");
            scanf("%d", &newVal);
            insertAfterNodeVal(nodeVal, newVal);
            printf("\nNode added successfully!\n");
            break;

        case 7:
            printf("\nEnter value: ");
            scanf("%d", &value);
            printf("\nEnter position: ");
            scanf("%d", &k);
            insertBeforeKthNode(value, k);
            printf("\nNode added before %dth node successfully!\n", k);
            break;

        case 8:
            printf("\nEnter value of node before which new node to be inserted: ");
            scanf("%d", &nodeVal);
            printf("\nEnter new node value: ");
            scanf("%d", &newVal);
            insertBeforeNodeVal(nodeVal, newVal);
            printf("\nNode added successfully!\n");
            break;

        case 9:
            deleteFirst();
            printf("\nFirst node is successfully deleted!\n");
            break;

        case 10:
            deleteLast();
            printf("\nLast node is successfully deleted!\n");
            break;

        case 11:
            printf("\nEnter position: ");
            scanf("%d", &k);
            deleteAfterKthNode(k);
            printf("\nNode after %dth position deleted successfully!\n", k);
            break;

        case 12:
            printf("\nEnter position: ");
            scanf("%d", &k);
            deleteBeforeKthNode(k);
            printf("\nNode before %dth position deleted successfully!\n", k);
            break;

        case 13:
            printf("\nEnter position: ");
            scanf("%d", &k);
            del_pos(&head, k);
            printf("\nNode at %dth position deleted successfully!\n", k);
            break;

        case 14:
            printf("\nEnter value to delete: ");
            scanf("%d", &value);
            deleteNodeWithValue(value);
            printf("\nNode with value %d deleted successfully!\n", value);
            break;

        case 15:
            reverseList();
            printf("\nList reversed successfully!\n");
            break;

        case 16:
            sortList();
            printf("\nList sorted successfully!\n");
            break;

        case 17:
            printf("\nEnter element to be searched: ");
            scanf("%d", &value);
            searchElement(value);
            break;

        case 18:
            createSecondList();
            mergeTwoLists();
            displayList(head2);
            break;

        case 19:
            createSecondList();
            concatenateLists();
            break;

        case 20:
            createSecondList();
            if (areListsEqual(head, head2))
                printf("\nThe two lists are equal.\n");
            else
                printf("\nThe two lists are not equal.\n");
            break;

        case 21:
            printf("\nExiting...\n");
            exit(0);

        default:
            printf("\nInvalid Choice!!!\n");
        }
    }
    return 0;
}