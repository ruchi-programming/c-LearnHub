#include <stdio.h>

void swap(int *first, int *second)
{
    int temporary = *first;
    *first = *second;
    *second = temporary;
}

int main(void)
{
    int number = 25;
    int *pointer = &number;

    printf("Value of number: %d\n", number);
    printf("Address of number: %p\n", (void *)&number);
    printf("Pointer stores: %p\n", (void *)pointer);
    printf("Value through pointer: %d\n", *pointer);

    *pointer = 40;
    printf("After *pointer = 40, number = %d\n", number);

    int a = 10, b = 20;
    swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);

    return 0;
}
