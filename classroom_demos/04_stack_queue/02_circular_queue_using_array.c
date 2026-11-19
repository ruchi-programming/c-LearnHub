#include <stdio.h>

#define QUEUE_CAPACITY 5

/*
 * Circular queue uses an array plus front, rear and count.
 * count distinguishes full from empty; no linked list is used.
 */
int enqueue(int queue[], int *rear, int *count, int capacity, int value)
{
    if (*count == capacity) {
        return 0; /* Overflow */
    }

    *rear = (*rear + 1) % capacity;
    queue[*rear] = value;
    ++(*count);
    return 1;
}

int dequeue(const int queue[], int *front, int *rear,
            int *count, int capacity, int *removedValue)
{
    if (*count == 0) {
        return 0; /* Underflow */
    }

    *removedValue = queue[*front];
    *front = (*front + 1) % capacity;
    --(*count);

    if (*count == 0) {
        *front = 0;
        *rear = -1;
    }
    return 1;
}

int getFront(const int queue[], int front, int count, int *frontValue)
{
    if (count == 0) {
        return 0;
    }

    *frontValue = queue[front];
    return 1;
}

void displayQueue(const int queue[], int front, int count, int capacity)
{
    if (count == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue (front to rear): ");
    for (int i = 0; i < count; ++i) {
        printf("%d ", queue[(front + i) % capacity]);
    }
    printf("\n");
}

int main(void)
{
    int queue[QUEUE_CAPACITY];
    int front = 0;
    int rear = -1;
    int count = 0;
    int choice, value;

    do {
        printf("\n--- Circular Queue using Array (capacity %d) ---\n",
               QUEUE_CAPACITY);
        printf("1. Enqueue\n2. Dequeue\n3. Show front\n4. Display\n0. Exit\nChoice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid menu input.\n");
            return 1;
        }

        switch (choice) {
        case 1:
            printf("Enter value: ");
            if (scanf("%d", &value) != 1) {
                printf("Invalid value.\n");
                return 1;
            }
            if (enqueue(queue, &rear, &count, QUEUE_CAPACITY, value)) {
                printf("%d enqueued. front = %d, rear = %d, count = %d\n",
                       value, front, rear, count);
            } else {
                printf("Queue overflow: queue is full.\n");
            }
            break;

        case 2:
            if (dequeue(queue, &front, &rear, &count,
                        QUEUE_CAPACITY, &value)) {
                printf("Dequeued value: %d; front = %d, rear = %d, count = %d\n",
                       value, front, rear, count);
            } else {
                printf("Queue underflow: queue is empty.\n");
            }
            break;

        case 3:
            if (getFront(queue, front, count, &value)) {
                printf("Front element: %d\n", value);
            } else {
                printf("Queue is empty.\n");
            }
            break;

        case 4:
            displayQueue(queue, front, count, QUEUE_CAPACITY);
            break;

        case 0:
            printf("Exiting queue demonstration.\n");
            break;

        default:
            printf("Choose 0 to 4.\n");
        }
    } while (choice != 0);

    return 0;
}
