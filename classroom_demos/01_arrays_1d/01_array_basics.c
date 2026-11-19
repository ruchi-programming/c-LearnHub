#include <stdio.h>

#define MAX_SIZE 100

int inputArray(int array[], int size)
{
    for (int i = 0; i < size; ++i) {
        printf("Enter element %d: ", i + 1);
        if (scanf("%d", &array[i]) != 1) {
            printf("Invalid integer input.\n");
            return 0;
        }
    }
    return 1;
}

void printArray(const int array[], int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int sumArray(const int array[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum;
}

int findMaximum(const int array[], int size)
{
    int maximum = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] > maximum) {
            maximum = array[i];
        }
    }
    return maximum;
}

int findMinimum(const int array[], int size)
{
    int minimum = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] < minimum) {
            minimum = array[i];
        }
    }
    return minimum;
}

/* Returns the first matching zero-based index, or -1 when not found. */
int linearSearch(const int array[], int size, int target)
{
    for (int i = 0; i < size; ++i) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

int countOccurrences(const int array[], int size, int target)
{
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] == target) {
            ++count;
        }
    }
    return count;
}

void printReverse(const int array[], int size)
{
    for (int i = size - 1; i >= 0; --i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void)
{
    int array[MAX_SIZE];
    int size;
    int target;

    printf("Enter array size (1-%d): ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size < 1 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    if (!inputArray(array, size)) {
        return 1;
    }

    printf("\nArray: ");
    printArray(array, size);
    printf("Sum: %d\n", sumArray(array, size));
    printf("Maximum: %d\n", findMaximum(array, size));
    printf("Minimum: %d\n", findMinimum(array, size));

    printf("Enter value to search/count: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid target.\n");
        return 1;
    }

    int index = linearSearch(array, size, target);
    if (index == -1) {
        printf("%d was not found.\n", target);
    } else {
        printf("%d found at index %d (position %d).\n",
               target, index, index + 1);
    }

    printf("Occurrences of %d: %d\n",
           target, countOccurrences(array, size, target));

    printf("Array printed in reverse (original unchanged): ");
    printReverse(array, size);

    return 0;
}
