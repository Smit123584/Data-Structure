#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

    //Aa function stack ma new value push kare chhe.
void push()
{
    int value;

    //Jo stack full hoy to overflow message aavse.
    if(top == MAX - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
     //User pase thi push karvani value lese.
        printf("Enter value to push: ");
        scanf("%d", &value);

        top++;
        stack[top] = value;

        printf("%d pushed into stack.\n", value);
    }
}

    //Aa function stack mathi top element delete kare chhe.
void pop()
{
    //Jo stack empty hoy to underflow message aavse.
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Deleted element is %d\n", stack[top]);
        top--;
    }
}

     //Aa function stack nu top element batave chhe.
void peek()
{
     //Jo stack empty hoy to empty message aavse.
    if(top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top element is %d\n", stack[top]);
    }
}

     //Aa function stack na badha elements display kare chhe.
void display()
{
    int i;

     //Jo stack empty hoy to empty message aavse.
    if(top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack elements are:\n");

     //Top thi 0 sudhi elements display thase.
        for(i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice;

      //Aa loop menu ne repeat karva mate chhe.
    do
    {
        printf("\n----- STACK MENU -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
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
                printf("Program Ended\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 5);

    return 0;
}