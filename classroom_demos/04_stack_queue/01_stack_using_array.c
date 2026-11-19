#include <stdio.h>

#define STACK_CAPACITY 5

/*
 * Stack operations use an array and a pointer to top.
 * top = -1 means empty; top = capacity - 1 means full.
 */
int push(int stack[], int *top, int capacity, int value)
{
    if (*top == capacity - 1) {
        return 0; /* Overflow */
    }

    stack[++(*top)] = value;
    return 1;
}

int pop(const int stack[], int *top, int *removedValue)
{
    if (*top == -1) {
        return 0; /* Underflow */
    }

    *removedValue = stack[*top];
    --(*top);
    return 1;
}

int peek(const int stack[], int top, int *topValue)
{
    if (top == -1) {
        return 0;
    }

    *topValue = stack[top];
    return 1;
}

void displayStack(const int stack[], int top)
{
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack (top to bottom):\n");
    for (int i = top; i >= 0; --i) {
        printf("%d\n", stack[i]);
    }
}

int main(void)
{
    int stack[STACK_CAPACITY];
    int top = -1;
    int choice, value;

    do {
        printf("\n--- Stack using Array (capacity %d) ---\n", STACK_CAPACITY);
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n0. Exit\nChoice: ");

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
            if (push(stack, &top, STACK_CAPACITY, value)) {
                printf("%d pushed. top = %d\n", value, top);
            } else {
                printf("Stack overflow: stack is full.\n");
            }
            break;

        case 2:
            if (pop(stack, &top, &value)) {
                printf("Popped value: %d; top = %d\n", value, top);
            } else {
                printf("Stack underflow: stack is empty.\n");
            }
            break;

        case 3:
            if (peek(stack, top, &value)) {
                printf("Top element: %d\n", value);
            } else {
                printf("Stack is empty.\n");
            }
            break;

        case 4:
            displayStack(stack, top);
            break;

        case 0:
            printf("Exiting stack demonstration.\n");
            break;

        default:
            printf("Choose 0 to 4.\n");
        }
    } while (choice != 0);

    return 0;
}
