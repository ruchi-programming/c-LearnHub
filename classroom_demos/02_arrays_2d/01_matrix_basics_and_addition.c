#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int inputMatrix(const char *name, int rows, int cols,
                 int matrix[MAX_ROWS][MAX_COLS])
{
    printf("Enter elements of %s:\n", name);
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

void addMatrices(int rows, int cols,
                 int first[MAX_ROWS][MAX_COLS],
                 int second[MAX_ROWS][MAX_COLS],
                 int result[MAX_ROWS][MAX_COLS])
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

long long rowSum(int cols,
                 int matrix[MAX_ROWS][MAX_COLS], int selectedRow)
{
    long long sum = 0;
    for (int j = 0; j < cols; ++j) {
        sum += matrix[selectedRow][j];
    }
    return sum;
}

long long columnSum(int rows,
                    int matrix[MAX_ROWS][MAX_COLS], int selectedColumn)
{
    long long sum = 0;
    for (int i = 0; i < rows; ++i) {
        sum += matrix[i][selectedColumn];
    }
    return sum;
}

/* For a rectangular matrix, sum the available main-diagonal elements. */
long long mainDiagonalSum(int rows, int cols,
                          int matrix[MAX_ROWS][MAX_COLS])
{
    int limit = rows < cols ? rows : cols;
    long long sum = 0;

    for (int i = 0; i < limit; ++i) {
        sum += matrix[i][i];
    }
    return sum;
}

void createIdentityMatrix(int order, int matrix[MAX_ROWS][MAX_COLS])
{
    for (int i = 0; i < order; ++i) {
        for (int j = 0; j < order; ++j) {
            matrix[i][j] = (i == j) ? 1 : 0;
        }
    }
}

int main(void)
{
    int rows, cols;
    int first[MAX_ROWS][MAX_COLS] = {{0}};
    int second[MAX_ROWS][MAX_COLS] = {{0}};
    int result[MAX_ROWS][MAX_COLS] = {{0}};
    int identity[MAX_ROWS][MAX_COLS] = {{0}};

    printf("Enter rows and columns (maximum %d x %d): ", MAX_ROWS, MAX_COLS);
    if (scanf("%d %d", &rows, &cols) != 2 ||
        rows < 1 || rows > MAX_ROWS || cols < 1 || cols > MAX_COLS) {
        printf("Invalid matrix dimensions.\n");
        return 1;
    }

    if (!inputMatrix("A", rows, cols, first) ||
        !inputMatrix("B", rows, cols, second)) {
        return 1;
    }

    addMatrices(rows, cols, first, second, result);

    displayMatrix("Matrix A", rows, cols, first);
    displayMatrix("Matrix B", rows, cols, second);
    displayMatrix("A + B", rows, cols, result);

    printf("Main diagonal sum of A: %lld\n",
           mainDiagonalSum(rows, cols, first));

    int selectedRow, selectedColumn;
    printf("Enter row index for row sum (0-%d): ", rows - 1);
    if (scanf("%d", &selectedRow) != 1 ||
        selectedRow < 0 || selectedRow >= rows) {
        printf("Invalid row index.\n");
        return 1;
    }

    printf("Enter column index for column sum (0-%d): ", cols - 1);
    if (scanf("%d", &selectedColumn) != 1 ||
        selectedColumn < 0 || selectedColumn >= cols) {
        printf("Invalid column index.\n");
        return 1;
    }

    printf("Row sum: %lld\n", rowSum(cols, first, selectedRow));
    printf("Column sum: %lld\n",
           columnSum(rows, first, selectedColumn));

    if (rows == cols) {
        createIdentityMatrix(rows, identity);
        displayMatrix("Identity matrix", rows, cols, identity);
    } else {
        printf("Identity matrix requires a square dimension.\n");
    }

    return 0;
}
