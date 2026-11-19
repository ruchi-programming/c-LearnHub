#include <stdio.h>

#define CAPACITY 5

int main(void)
{
    int queue[CAPACITY];
    int front = 0, rear = -1, count = 0;
    int choice, value;

    do {
        printf("\n1.Enqueue  2.Dequeue  3.Display  0.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) return 1;

        switch (choice) {
        case 1:
            if (count == CAPACITY) {
                printf("Queue overflow.\n");
                break;
            }
            printf("Value: ");
            if (scanf("%d", &value) != 1) return 1;
            rear = (rear + 1) % CAPACITY;
            queue[rear] = value;
            ++count;
            break;
        case 2:
            if (count == 0) {
                printf("Queue underflow.\n");
            } else {
                printf("Dequeued: %d\n", queue[front]);
                front = (front + 1) % CAPACITY;
                --count;
                if (count == 0) {
                    front = 0;
                    rear = -1;
                }
            }
            break;
        case 3:
            if (count == 0) {
                printf("Queue is empty.\n");
            } else {
                for (int i = 0; i < count; ++i)
                    printf("%d ", queue[(front + i) % CAPACITY]);
                printf("\n");
            }
            break;
        case 0:
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
