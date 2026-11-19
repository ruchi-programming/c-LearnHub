#include <stdio.h>

#define CAPACITY 5

int main(void)
{
    int stack[CAPACITY];
    int top = -1;
    int choice, value;

    do {
        printf("\n1.Push  2.Pop  3.Peek  4.Display  0.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) return 1;

        switch (choice) {
        case 1:
            if (top == CAPACITY - 1) {
                printf("Stack overflow.\n");
                break;
            }
            printf("Value: ");
            if (scanf("%d", &value) != 1) return 1;
            stack[++top] = value;
            break;
        case 2:
            if (top == -1) printf("Stack underflow.\n");
            else printf("Popped: %d\n", stack[top--]);
            break;
        case 3:
            if (top == -1) printf("Stack is empty.\n");
            else printf("Top: %d\n", stack[top]);
            break;
        case 4:
            if (top == -1) printf("Stack is empty.\n");
            for (int i = top; i >= 0; --i) printf("%d\n", stack[i]);
            break;
        case 0:
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
