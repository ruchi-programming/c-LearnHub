#include <stdio.h>

#define MAX_SIZE 100

void printArray(const int array[], int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int *first, int *second)
{
    int temporary = *first;
    *first = *second;
    *second = temporary;
}

/* Reverses the actual array by swapping matching elements at both ends. */
void reverseArray(int array[], int size)
{
    for (int left = 0, right = size - 1; left < right; ++left, --right) {
        swap(&array[left], &array[right]);
    }
}

void incrementElements(int array[], int size)
{
    for (int i = 0; i < size; ++i) {
        ++array[i];
    }
}

/* Replaces each element with the sum of itself and all previous elements. */
void calculateRunningSum(int array[], int size)
{
    for (int i = 1; i < size; ++i) {
        array[i] += array[i - 1];
    }
}

void copyArray(const int source[], int destination[], int size)
{
    for (int i = 0; i < size; ++i) {
        destination[i] = source[i];
    }
}

int main(void)
{
    int array[MAX_SIZE];
    int copied[MAX_SIZE];
    int size;

    printf("Enter array size (1-%d): ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size < 1 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    for (int i = 0; i < size; ++i) {
        printf("Element %d: ", i + 1);
        if (scanf("%d", &array[i]) != 1) {
            printf("Invalid element.\n");
            return 1;
        }
    }

    copyArray(array, copied, size);
    printf("Original array: ");
    printArray(array, size);

    reverseArray(array, size);
    printf("After reversing the array: ");
    printArray(array, size);

    incrementElements(array, size);
    printf("After incrementing each element: ");
    printArray(array, size);

    calculateRunningSum(array, size);
    printf("After running-sum operation: ");
    printArray(array, size);

    printf("Saved copy (unchanged): ");
    printArray(copied, size);

    return 0;
}
