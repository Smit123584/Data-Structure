#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Circular Queue is Full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) %MAX;
        }

        queue[rear] = value;
        printf("%d insert into queue\n", value);
    }
}


void dequeue()
{
    if (front == -1)
    {
        printf("Circular Queue is Empty\n");
    }
    else
    {
        printf("%d deleted from queue\n", queue[front]);

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}


void display()
{
    int i;

    if (front == -1)
    {
        printf("Circular Queue is Empty\n");
    }
    else
    {
        printf("Circular Queue elements are: ");

        i = front;

        while (1)
        {
            printf("%d ", queue[i]);

            if (i == rear)
            {
                break;
            }

            i = (i + 1) % MAX;
        }

        printf("\n");
    }
}


int main()
{
    int choice, value;

    while (1)
    {
        printf("\n---- CIRCULAR QUEUE MENU ----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
       

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
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