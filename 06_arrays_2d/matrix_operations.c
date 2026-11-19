#include <stdio.h>

#define MAX 10

void readMatrix(int rows, int cols, int matrix[MAX][MAX])
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int rows, int cols, int matrix[MAX][MAX])
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int rows, cols;
    int first[MAX][MAX], second[MAX][MAX], result[MAX][MAX];

    printf("Enter rows and columns (1-%d): ", MAX);
    if (scanf("%d %d", &rows, &cols) != 2 ||
        rows < 1 || rows > MAX || cols < 1 || cols > MAX) {
        printf("Invalid dimensions.\n");
        return 1;
    }

    printf("Enter first matrix:\n");
    readMatrix(rows, cols, first);
    printf("Enter second matrix:\n");
    readMatrix(rows, cols, second);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }

    printf("First matrix:\n");
    displayMatrix(rows, cols, first);
    printf("Second matrix:\n");
    displayMatrix(rows, cols, second);
    printf("Sum:\n");
    displayMatrix(rows, cols, result);

    printf("Transpose of first matrix:\n");
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            printf("%4d", first[i][j]);
        }
        printf("\n");
    }

    return 0;
}
