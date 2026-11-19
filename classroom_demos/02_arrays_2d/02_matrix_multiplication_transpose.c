#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int inputMatrix(const char *name, int rows, int cols,
                 int matrix[MAX_ROWS][MAX_COLS])
{
    printf("Enter matrix %s:\n", name);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%s[%d][%d]: ", name, i, j);
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid matrix element.\n");
                return 0;
            }
        }
    }
    return 1;
}

void displayMatrix(const char *name, int rows, int cols,
                   int matrix[MAX_ROWS][MAX_COLS])
{
    printf("%s:\n", name);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

/*
 * A is rowsA x colsA; B is rowsB x colsB.
 * Multiplication is valid only when colsA == rowsB.
 * Result dimensions are rowsA x colsB.
 */
void multiplyMatrices(int rowsA, int colsA, int colsB,
                      int first[MAX_ROWS][MAX_COLS],
                      int second[MAX_ROWS][MAX_COLS],
                      int result[MAX_ROWS][MAX_COLS])
{
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

void transposeMatrix(int rows, int cols,
                     int original[MAX_ROWS][MAX_COLS],
                     int transposed[MAX_COLS][MAX_ROWS])
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = original[i][j];
        }
    }
}

int main(void)
{
    int rowsA, colsA, rowsB, colsB;
    int first[MAX_ROWS][MAX_COLS] = {{0}};
    int second[MAX_ROWS][MAX_COLS] = {{0}};
    int product[MAX_ROWS][MAX_COLS] = {{0}};
    int transposed[MAX_COLS][MAX_ROWS] = {{0}};

    printf("Enter rows and columns of A: ");
    if (scanf("%d %d", &rowsA, &colsA) != 2 ||
        rowsA < 1 || rowsA > MAX_ROWS || colsA < 1 || colsA > MAX_COLS) {
        printf("Invalid dimensions for A.\n");
        return 1;
    }

    printf("Enter rows and columns of B: ");
    if (scanf("%d %d", &rowsB, &colsB) != 2 ||
        rowsB < 1 || rowsB > MAX_ROWS || colsB < 1 || colsB > MAX_COLS) {
        printf("Invalid dimensions for B.\n");
        return 1;
    }

    if (colsA != rowsB) {
        printf("Multiplication is not possible: columns of A must equal rows of B.\n");
        return 1;
    }

    if (!inputMatrix("A", rowsA, colsA, first) ||
        !inputMatrix("B", rowsB, colsB, second)) {
        return 1;
    }

    multiplyMatrices(rowsA, colsA, colsB, first, second, product);
    displayMatrix("A x B", rowsA, colsB, product);

    transposeMatrix(rowsA, colsA, first, transposed);
    printf("Transpose of A:\n");
    for (int i = 0; i < colsA; ++i) {
        for (int j = 0; j < rowsA; ++j) {
            printf("%5d", transposed[i][j]);
        }
        printf("\n");
    }

    return 0;
}
