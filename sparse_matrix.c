#include <stdio.h>

#define MAX 20

int main() {
    int matrix[MAX][MAX];
    int sparse[MAX][3];   // sparse[i][0] = row, sparse[i][1] = column, sparse[i][2] = value
    int rows, cols, i, j, k = 0;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("\nEnter the elements of the matrix:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Storing non-zero elements
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) {
                sparse[k][0] = i;          // Row
                sparse[k][1] = j;          // Column
                sparse[k][2] = matrix[i][j]; // Value
                k++;
            }
        }
    }

    // Display Original Matrix
    printf("\nOriginal Matrix:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Display Sparse Matrix (Triplet Form)
    printf("\nSparse Matrix Representation (Row  Column  Value):\n");
    printf("Row\tColumn\tValue\n");
    for(i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    printf("\nTotal non-zero elements = %d\n", k);

    return 0;
}