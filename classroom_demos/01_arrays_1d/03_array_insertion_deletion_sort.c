#include <stdio.h>

#define CAPACITY 100

void printArray(const int array[], int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/*
 * Inserts at a zero-based index from 0 through *size.
 * The pointer lets this function update the caller's logical size.
 */
int insertAt(int array[], int *size, int capacity, int index, int value)
{
    if (size == NULL || index < 0 || index > *size || *size >= capacity) {
        return 0;
    }

    for (int i = *size; i > index; --i) {
        array[i] = array[i - 1];
    }

    array[index] = value;
    ++(*size);
    return 1;
}

/*
 * Deletes at a zero-based index and stores the removed value through a pointer.
 */
int deleteAt(int array[], int *size, int index, int *removedValue)
{
    if (size == NULL || removedValue == NULL || index < 0 || index >= *size) {
        return 0;
    }

    *removedValue = array[index];

    for (int i = index; i < *size - 1; ++i) {
        array[i] = array[i + 1];
    }

    --(*size);
    return 1;
}

/* Insertion sort: maintains a sorted prefix and inserts the next value into it. */
void insertionSort(int array[], int size)
{
    for (int i = 1; i < size; ++i) {
        int value = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > value) {
            array[j + 1] = array[j];
            --j;
        }

        array[j + 1] = value;
    }
}

int main(void)
{
    int array[CAPACITY] = {12, 5, 8, 20, 3};
    int size = 5;
    int removedValue;

    printf("Initial array: ");
    printArray(array, size);

    if (insertAt(array, &size, CAPACITY, 2, 99)) {
        printf("After inserting 99 at position 3: ");
        printArray(array, size);
    } else {
        printf("Insertion failed.\n");
    }

    if (deleteAt(array, &size, 1, &removedValue)) {
        printf("Deleted value: %d\n", removedValue);
        printf("After deletion: ");
        printArray(array, size);
    } else {
        printf("Deletion failed.\n");
    }

    insertionSort(array, size);
    printf("After insertion sort: ");
    printArray(array, size);

    return 0;
}
