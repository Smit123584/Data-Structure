#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;


void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;

        printf("%d inserted into queue\n", value);
    }
}


void dequeue()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("%d deleted from queue\n", queue[front]);

        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}


void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue elements are: ");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}


int main()
{
    int choice;
    int value;

    while (1)
    {
        printf("\n----- Queue Menu -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("--\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}