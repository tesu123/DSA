#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define MAX_QUEUES 10

typedef struct
{
    int front;
    int rear;
    int size;
} QueueInfo;

QueueInfo queues[MAX_QUEUES];
int data[MAX_SIZE];
int queue_count = 0;
int next_free = 0;

int create_queue()
{
    if (queue_count >= MAX_QUEUES)
    {
        printf("Maximum number of queues reached\n");
        return -1;
    }
    if (next_free >= MAX_SIZE)
    {
        printf("No space left for new queue\n");
        return -1;
    }

    queues[queue_count].front = -1;
    queues[queue_count].rear = -1;
    queues[queue_count].size = 0;

    printf("Queue %d created successfully\n", queue_count);
    return queue_count++;
}

void enqueue(int queue_id, int value)
{
    if (queue_id < 0 || queue_id >= queue_count)
    {
        printf("Invalid queue ID\n");
        return;
    }

    if (next_free >= MAX_SIZE)
    {
        printf("System out of memory\n");
        return;
    }

    if (queues[queue_id].front == -1)
    {
        queues[queue_id].front = next_free;
        queues[queue_id].rear = next_free;
    }
    else
    {
        queues[queue_id].rear = next_free;
    }

    data[next_free++] = value;
    queues[queue_id].size++;
}

int dequeue(int queue_id)
{
    if (queue_id < 0 || queue_id >= queue_count)
    {
        printf("Invalid queue ID\n");
        return -1;
    }

    if (queues[queue_id].front == -1)
    {
        printf("Queue %d is empty\n", queue_id);
        return -1;
    }

    int value = data[queues[queue_id].front];
    queues[queue_id].front++;
    queues[queue_id].size--;

    if (queues[queue_id].front > queues[queue_id].rear)
    {
        queues[queue_id].front = -1;
        queues[queue_id].rear = -1;
    }

    return value;
}

void display_queue(int queue_id)
{
    if (queue_id < 0 || queue_id >= queue_count)
    {
        printf("Invalid queue ID\n");
        return;
    }

    if (queues[queue_id].front == -1)
    {
        printf("Queue %d is empty\n", queue_id);
        return;
    }

    printf("Queue %d: [", queue_id);
    for (int i = queues[queue_id].front; i <= queues[queue_id].rear; i++)
    {
        printf("%d", data[i]);
        if (i < queues[queue_id].rear)
            printf(", ");
    }
    printf("]\n");
}

void append_queue(int x, int y)
{
    if (x < 0 || x >= queue_count || y < 0 || y >= queue_count)
    {
        printf("Invalid queue ID\n");
        return;
    }

    if (queues[x].front == -1)
    {
        printf("Queue %d is empty - nothing to append\n", x);
        return;
    }

    // Check if there's enough space
    if (next_free + queues[x].size > MAX_SIZE)
    {
        printf("Not enough space to append queue\n");
        return;
    }

    // If queue y is empty, just copy queue x
    if (queues[y].front == -1)
    {
        queues[y].front = next_free;
        for (int i = queues[x].front; i <= queues[x].rear; i++)
        {
            data[next_free++] = data[i];
        }
        queues[y].rear = next_free - 1;
        queues[y].size = queues[x].size;
    }
    else
    {
        // Append queue x to queue y
        int old_y_rear = queues[y].rear;
        queues[y].rear = next_free + (queues[x].size - 1);

        for (int i = queues[x].front; i <= queues[x].rear; i++)
        {
            data[next_free++] = data[i];
        }

        queues[y].size += queues[x].size;
    }

    printf("Queue %d appended to queue %d\n", x, y);
}

int main()
{
    int choice, x, y, value;

    // Create some queues for testing
    int q1 = create_queue();
    int q2 = create_queue();

    // Add some test data
    enqueue(q1, 10);
    enqueue(q1, 20);
    enqueue(q1, 30);
    enqueue(q2, 40);
    enqueue(q2, 50);

    while (1)
    {
        printf("\nMulti-Queue System\n");
        printf("1. Create new queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Display queue\n");
        printf("5. Append queue x to queue y\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create_queue();
            break;
        case 2:
            printf("Enter queue ID: ");
            scanf("%d", &x);
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(x, value);
            break;
        case 3:
            printf("Enter queue ID: ");
            scanf("%d", &x);
            value = dequeue(x);
            if (value != -1)
            {
                printf("Dequeued value: %d\n", value);
            }
            break;
        case 4:
            printf("Enter queue ID: ");
            scanf("%d", &x);
            display_queue(x);
            break;
        case 5:
            printf("Enter queue ID to append (x): ");
            scanf("%d", &x);
            printf("Enter destination queue ID (y): ");
            scanf("%d", &y);
            append_queue(x, y);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}