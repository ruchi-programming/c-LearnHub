#include <stdio.h>

int main(void)
{
    int limit;

    printf("Enter a positive limit: ");
    if (scanf("%d", &limit) != 1 || limit < 1) {
        printf("Invalid limit.\n");
        return 1;
    }

    printf("Using for: ");
    for (int i = 1; i <= limit; ++i) {
        printf("%d ", i);
    }

    printf("\nUsing while: ");
    int i = 1;
    while (i <= limit) {
        printf("%d ", i);
        ++i;
    }

    printf("\nUsing do-while: ");
    i = 1;
    do {
        printf("%d ", i);
        ++i;
    } while (i <= limit);

    printf("\n");
    return 0;
}
