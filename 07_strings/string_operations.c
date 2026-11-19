#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

int main(void)
{
    char first[SIZE], second[SIZE];

    printf("Enter first line: ");
    if (fgets(first, sizeof first, stdin) == NULL) return 1;
    first[strcspn(first, "\n")] = '\0';

    printf("Enter second line: ");
    if (fgets(second, sizeof second, stdin) == NULL) return 1;
    second[strcspn(second, "\n")] = '\0';

    printf("First length: %zu\n", strlen(first));
    printf("Comparison result: %d\n", strcmp(first, second));

    if (strlen(first) + strlen(second) < SIZE) {
        strcat(first, second);
        printf("Concatenated: %s\n", first);
    } else {
        printf("Combined string is too long for the destination buffer.\n");
    }

    return 0;
}
