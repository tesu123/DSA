#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 // Total space for all queues
#define MAX_QUEUES 10 // Maximum number of queues

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
    printf("Enqueued %d to queue %d\n", value, queue_id);
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

    printf("Dequeued %d from queue %d\n", value, queue_id);
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

int main()
{
    int choice, queue_id, value;

    while (1)
    {
        printf("\nMulti-Queue System\n");
        printf("1. Create new queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Display queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            queue_id = create_queue();
            break;
        case 2:
            printf("Enter queue ID: ");
            scanf("%d", &queue_id);
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(queue_id, value);
            break;
        case 3:
            printf("Enter queue ID: ");
            scanf("%d", &queue_id);
            dequeue(queue_id);
            break;
        case 4:
            printf("Enter queue ID: ");
            scanf("%d", &queue_id);
            display_queue(queue_id);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}