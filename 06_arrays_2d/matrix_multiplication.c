#include <stdio.h>

#define MAX 10

int main(void)
{
    int rowsA, colsA, rowsB, colsB;
    int a[MAX][MAX], b[MAX][MAX], product[MAX][MAX] = {0};

    printf("Enter rows and columns of A: ");
    if (scanf("%d %d", &rowsA, &colsA) != 2 ||
        rowsA < 1 || rowsA > MAX || colsA < 1 || colsA > MAX) {
        printf("Invalid dimensions.\n");
        return 1;
    }

    printf("Enter rows and columns of B: ");
    if (scanf("%d %d", &rowsB, &colsB) != 2 ||
        rowsB < 1 || rowsB > MAX || colsB < 1 || colsB > MAX) {
        printf("Invalid dimensions.\n");
        return 1;
    }

    if (colsA != rowsB) {
        printf("Multiplication is not possible: columns of A must equal rows of B.\n");
        return 1;
    }

    printf("Enter A:\n");
    for (int i = 0; i < rowsA; ++i)
        for (int j = 0; j < colsA; ++j)
            if (scanf("%d", &a[i][j]) != 1) return 1;

    printf("Enter B:\n");
    for (int i = 0; i < rowsB; ++i)
        for (int j = 0; j < colsB; ++j)
            if (scanf("%d", &b[i][j]) != 1) return 1;

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Product:\n");
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j)
            printf("%4d", product[i][j]);
        printf("\n");
    }

    return 0;
}
