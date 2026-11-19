#include <stdio.h>

int main(void)
{
    int rows;

    printf("Enter number of rows (1-20): ");
    if (scanf("%d", &rows) != 1 || rows < 1 || rows > 20) {
        printf("Invalid row count.\n");
        return 1;
    }

    printf("\n1. Right-angled star triangle\n");
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n2. Inverted star triangle\n");
    for (int i = rows; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n3. Number triangle\n");
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("%d ", j);
        }
        printf("\n");
    }

    printf("\n4. Repeated-row number triangle\n");
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}
