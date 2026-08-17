#include <stdio.h>

// Maximum size of the queue
#define MAX 5

// Array used to store queue elements
int queue[MAX];

// 'front' points to the first element
// 'rear' points to the last element
int front = -1;
int rear = -1;


/*
    Function: enqueue()

    Purpose:
    Adds a new element at the rear of the queue.
*/
void enqueue()
{
    int value;

    // Check if the queue is full
    if (rear == MAX - 1)
    {
        printf("\nQueue Overflow!");
        printf("\nThe queue is full. Cannot insert more elements.\n");
    }
    else
    {
        // Take the value from the user
        printf("\nEnter the value to enqueue: ");
        scanf("%d", &value);

        // If this is the first element
        if (front == -1)
        {
            front = 0;
        }

        // Move rear to the next position
        rear++;

        // Store the value at rear
        queue[rear] = value;

        printf("%d has been added to the queue.\n", value);
    }
}


/*
    Function: dequeue()

    Purpose:
    Removes the element from the front of the queue.
*/
void dequeue()
{
    // Check if the queue is empty
    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow!");
        printf("\nThe queue is empty. Nothing to remove.\n");
    }
    else
    {
        // Display the element being removed
        printf("\n%d has been removed from the queue.\n",
               queue[front]);

        // Move front to the next element
        front++;

        // If all elements have been removed
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}


/*
    Function: peek()

    Purpose:
    Displays the front element without removing it.
*/
void peek()
{
    // Check if the queue is empty
    if (front == -1)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        // Display the front element
        printf("\nFront element = %d\n", queue[front]);
    }
}


/*
    Function: display()

    Purpose:
    Displays all elements of the queue
    from front to rear.
*/
void display()
{
    int i;

    // Check if the queue is empty
    if (front == -1)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("\nQueue elements are:\n");

        // Display elements from front to rear
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}


/*
    Function: main()

    Purpose:
    Displays the menu and allows the user
    to select different queue operations.
*/
int main()
{
    int choice;

    // Continue displaying the menu
    // until the user chooses Exit
    while (1)
    {
        printf("\n\n========== QUEUE MENU ==========\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("================================\n");

        // Take the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform operation according to choice
        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nProgram terminated successfully.\n");
                return 0;

            default:
                printf("\nInvalid choice!");
                printf("\nPlease enter a number between 1 and 5.\n");
        }
    }

    return 0;
}