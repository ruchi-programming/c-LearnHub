#include <stdio.h>

int main(void)
{
    int values[] = {10, 20, 30, 40};
    int size = (int)(sizeof values / sizeof values[0]);
    int *pointer = values;

    for (int i = 0; i < size; ++i) {
        printf("Index %d: array[i] = %d, *(pointer + i) = %d\n",
               i, values[i], *(pointer + i));
    }

    return 0;
}
