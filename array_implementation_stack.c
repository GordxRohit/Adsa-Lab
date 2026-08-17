/*
    Program: Stack Implementation Using Array

    Description:
    This program implements a stack using an array.
    The program allows the user to perform:
    1. Push
    2. Pop
    3. Peek
    4. Display
    5. Exit

    Stack follows the LIFO principle:
    Last In, First Out.
*/

#include <stdio.h>

// Maximum size of the stack
#define MAX 5

// Array used to store stack elements
int stack[MAX];

// 'top' stores the index of the top element
// -1 means that the stack is empty
int top = -1;


/*
    Function: push()

    Purpose:
    Adds a new element to the top of the stack.
*/
void push()
{
    int value;

    // Check if the stack is already full
    if (top == MAX - 1)
    {
        printf("\nStack Overflow!");
        printf("\nThe stack is full. Cannot insert more elements.\n");
    }
    else
    {
        // Take the element from the user
        printf("\nEnter the value to push: ");
        scanf("%d", &value);

        // Move top to the next position
        top++;

        // Store the value at the top position
        stack[top] = value;

        printf("%d has been pushed into the stack.\n", value);
    }
}


/*
    Function: pop()

    Purpose:
    Removes the top element from the stack.
*/
void pop()
{
    // Check if the stack is empty
    if (top == -1)
    {
        printf("\nStack Underflow!");
        printf("\nThe stack is empty. Nothing to remove.\n");
    }
    else
    {
        // Display the element being removed
        printf("\n%d has been popped from the stack.\n",
               stack[top]);

        // Move top one position down
        top--;
    }
}


/*
    Function: peek()

    Purpose:
    Displays the top element without removing it.
*/
void peek()
{
    // Check if the stack is empty
    if (top == -1)
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        // Display the top element
        printf("\nTop element = %d\n", stack[top]);
    }
}


/*
    Function: display()

    Purpose:
    Displays all elements of the stack
    from top to bottom.
*/
void display()
{
    int i;

    // Check if the stack is empty
    if (top == -1)
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\nStack elements are:\n");

        // Start from top and move towards bottom
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}


/*
    Function: main()

    Purpose:
    Displays the menu and allows the user
    to select different stack operations.
*/
int main()
{
    int choice;

    // Continue displaying the menu
    // until the user chooses Exit
    while (1)
    {
        printf("\n\n========== STACK MENU ==========\n");
        printf("1. Push\n");
        printf("2. Pop\n");
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
                push();
                break;

            case 2:
                pop();
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