#include <stdio.h>

#define CAPACITY 100

int insertAt(int array[], int *size, int index, int value)
{
    if (index < 0 || index > *size || *size >= CAPACITY) {
        return 0;
    }

    for (int i = *size; i > index; --i) {
        array[i] = array[i - 1];
    }

    array[index] = value;
    ++(*size);
    return 1;
}

int deleteAt(int array[], int *size, int index, int *removed)
{
    if (index < 0 || index >= *size) {
        return 0;
    }

    *removed = array[index];
    for (int i = index; i < *size - 1; ++i) {
        array[i] = array[i + 1];
    }

    --(*size);
    return 1;
}

int main(void)
{
    int array[CAPACITY] = {10, 20, 30, 40};
    int size = 4;
    int removed;

    printf("Original: ");
    for (int i = 0; i < size; ++i) printf("%d ", array[i]);

    if (insertAt(array, &size, 2, 99)) {
        printf("\nAfter inserting 99 at index 2: ");
        for (int i = 0; i < size; ++i) printf("%d ", array[i]);
    }

    if (deleteAt(array, &size, 1, &removed)) {
        printf("\nDeleted value %d. Updated array: ", removed);
        for (int i = 0; i < size; ++i) printf("%d ", array[i]);
    }

    printf("\n");
    return 0;
}
