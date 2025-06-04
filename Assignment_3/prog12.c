#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

    if (next_free + queues[x].size > MAX_SIZE)
    {
        printf("Not enough space to append queue\n");
        return;
    }

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

bool eq(int q1, int q2)
{
    if (q1 < 0 || q1 >= queue_count || q2 < 0 || q2 >= queue_count)
    {
        return false;
    }

    if (queues[q1].size != queues[q2].size)
    {
        return false;
    }

    if (queues[q1].front == -1 && queues[q2].front == -1)
    {
        return true;
    }

    int i = queues[q1].front;
    int j = queues[q2].front;

    while (i <= queues[q1].rear && j <= queues[q2].rear)
    {
        if (data[i] != data[j])
        {
            return false;
        }
        i++;
        j++;
    }

    return true;
}

int main()
{
    int choice, x, y, value;

    while (1)
    {
        printf("\nMulti-Queue System\n");
        printf("1. Create new queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Display queue\n");
        printf("5. Append queue x to queue y\n");
        printf("6. Check if two queues are equal\n");
        printf("7. Exit\n");
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
            printf("Enter first queue ID: ");
            scanf("%d", &x);
            printf("Enter second queue ID: ");
            scanf("%d", &y);
            if (eq(x, y))
            {
                printf("Queues %d and %d are equal\n", x, y);
            }
            else
            {
                printf("Queues %d and %d are NOT equal\n", x, y);
            }
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}