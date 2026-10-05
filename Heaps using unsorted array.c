#include <stdio.h>

int heap[50];     // array to store heap
int size = 0;     // current number of elements

// swap two values
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// move node up to fix heap
void heapifyUp(int i) {
    while(i > 0) {
        int parent = (i - 1) / 2;
        if(heap[i] > heap[parent]) {
            swap(&heap[i], &heap[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

// move node down to fix heap
void heapifyDown(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && heap[left] > heap[largest])
        largest = left;

    if(right < size && heap[right] > heap[largest])
        largest = right;

    if(largest != i) {
        swap(&heap[i], &heap[largest]);
        heapifyDown(largest);
    }
}

// insert value into heap
void insert(int val) {
    heap[size] = val;     // put at end
    heapifyUp(size);      // fix the heap
    size++;
    printf("Inserted %d\n", val);
}

// build heap from unsorted array
void buildHeap(int arr[], int n) {
    int i;
    size = n;

    // copy values into heap
    for(i = 0; i < n; i++)
        heap[i] = arr[i];

    // start from last parent and fix heap
    for(i = (n / 2) - 1; i >= 0; i--)
        heapifyDown(i);

    printf("Heap built from unsorted array\n");
}

// show heap array
void display() {
    int i;
    if(size == 0) {
        printf("Heap is empty\n");
        return;
    }
    printf("Heap: ");
    for(i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int arr[50], n, i, ch, val;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter unsorted elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    buildHeap(arr, n);
    display();

    while(1) {
        printf("\n1.Insert 2.Display 3.Exit\nChoice: ");
        scanf("%d", &ch);

        if(ch == 1) {
            printf("Value: ");
            scanf("%d", &val);
            insert(val);
        }
        else if(ch == 2)
            display();
        else if(ch == 3)
            break;
        else
            printf("Invalid\n");
    }
    return 0;
}