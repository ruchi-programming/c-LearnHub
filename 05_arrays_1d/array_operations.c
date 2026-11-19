#include <stdio.h>

#define MAX_SIZE 100

void display(const int array[], int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int sum(const int array[], int size)
{
    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += array[i];
    }
    return total;
}

int linearSearch(const int array[], int size, int target)
{
    for (int i = 0; i < size; ++i) {
        if (array[i] == target) {
            return i; /* Zero-based index. */
        }
    }
    return -1;
}

void reverse(int array[], int size)
{
    for (int left = 0, right = size - 1; left < right; ++left, --right) {
        int temporary = array[left];
        array[left] = array[right];
        array[right] = temporary;
    }
}

void selectionSort(int array[], int size)
{
    for (int i = 0; i < size - 1; ++i) {
        int minimumIndex = i;

        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[minimumIndex]) {
                minimumIndex = j;
            }
        }

        int temporary = array[i];
        array[i] = array[minimumIndex];
        array[minimumIndex] = temporary;
    }
}

int main(void)
{
    int array[MAX_SIZE];
    int size, target;

    printf("Enter array size (1-%d): ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size < 1 || size > MAX_SIZE) {
        printf("Invalid size.\n");
        return 1;
    }

    for (int i = 0; i < size; ++i) {
        printf("Element %d: ", i + 1);
        if (scanf("%d", &array[i]) != 1) {
            printf("Invalid element.\n");
            return 1;
        }
    }

    printf("Array: ");
    display(array, size);
    printf("Sum: %d\n", sum(array, size));

    printf("Value to search: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid target.\n");
        return 1;
    }

    int index = linearSearch(array, size, target);
    if (index == -1) {
        printf("Not found.\n");
    } else {
        printf("Found at index %d (position %d).\n", index, index + 1);
    }

    reverse(array, size);
    printf("Reversed: ");
    display(array, size);

    selectionSort(array, size);
    printf("Sorted ascending: ");
    display(array, size);

    return 0;
}
