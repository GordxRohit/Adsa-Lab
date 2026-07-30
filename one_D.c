#include <stdio.h>
#define MAX 50

int main() {
    int arr[MAX], n = 0, choice, pos, val, i, key, found;

    while(1) {
        printf("\n----- 1D Array Menu -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &val);
                for(i = n; i > pos; i--)
                    arr[i] = arr[i-1];
                arr[pos] = val;
                n++;
                printf("Inserted\n");
                break;

            case 2: 
                printf("Enter position: ");
                scanf("%d", &pos);
                for(i = pos; i < n-1; i++)
                    arr[i] = arr[i+1];
                n--;
                printf("Deleted\n");
                break;

            case 3: 
                printf("Enter element: ");
                scanf("%d", &key);
                found = 0;
                for(i = 0; i < n; i++) {
                    if(arr[i] == key) {
                        printf("Found at %d\n", i);
                        found = 1;
                    }
                }
                if(found == 0)
                    printf("Not Found\n");
                break;

            case 4: 
                printf("Array: ");
                for(i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}