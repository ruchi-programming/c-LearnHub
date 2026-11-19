#include <stdio.h>

/* Function declaration (prototype). */
int maximum(int first, int second);

int main(void)
{
    int a, b;

    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Maximum = %d\n", maximum(a, b));
    return 0;
}

/* Function definition. */
int maximum(int first, int second)
{
    return first > second ? first : second;
}
