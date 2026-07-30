#include <stdio.h>
#define MAX 50

int main() {
    int a[MAX][MAX], b[MAX][MAX];
    int r = 0, c = 0, choice, i, j;

    while(1) {
        printf("\n----- 2D Array Menu -----\n");
        printf("1. Create 2D\n");
        printf("2. Addition of 2D\n");
        printf("3. Transpose of matrix\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Create 2D
                printf("Enter rows: ");
                scanf("%d", &r);
                printf("Enter columns: ");
                scanf("%d", &c);
                printf("Enter elements:\n");
                for(i = 0; i < r; i++)
                    for(j = 0; j < c; j++)
                        scanf("%d", &a[i][j]);
                printf("Matrix Created\n");
                break;

            case 2: 
                if(r == 0) {
                    printf("Create matrix first!\n");
                    break;
                }
                printf("Enter second matrix:\n");
                for(i = 0; i < r; i++)
                    for(j = 0; j < c; j++)
                        scanf("%d", &b[i][j]);

                printf("\nAddition Result:\n");
                for(i = 0; i < r; i++) {
                    for(j = 0; j < c; j++)
                        printf("%d\t", a[i][j] + b[i][j]);
                    printf("\n");
                }
                break;

            case 3: // Transpose
                if(r == 0) {
                    printf("Create matrix first!\n");
                    break;
                }
                printf("\nTranspose:\n");
                for(i = 0; i < c; i++) {
                    for(j = 0; j < r; j++)
                        printf("%d\t", a[j][i]);
                    printf("\n");
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}