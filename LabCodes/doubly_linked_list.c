#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insert(int value, int pos)
{
    struct node *newnode, *temp;
    int i;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (pos == 1)
    {
        newnode->next = head;

        if (head != NULL)
            head->prev = newnode;

        head = newnode;
    }
    else
    {
        temp = head;

        for (i = 1; i < pos - 1; i++)
            temp = temp->next;

        newnode->next = temp->next;
        newnode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newnode;

        temp->next = newnode;
    }
}

void deleteNode(int pos)
{
    struct node *temp;
    int i;

    temp = head;

    if (pos == 1)
    {
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        free(temp);
    }
    else
    {
        for (i = 1; i < pos; i++)
            temp = temp->next;

        temp->prev->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        free(temp);
    }
}

void displayLeftToRight()
{
    struct node *temp;

    temp = head;

    printf("\nLeft to Right: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void displayRightToLeft()
{
    struct node *temp;

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    printf("\nRight to Left: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

int main()
{
    int choice, value, pos;

    while (1)
    {
        printf("\n\n--- DOUBLY LINKED LIST ---");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display Left to Right");
        printf("\n4. Display Right to Left");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                printf("Enter position: ");
                scanf("%d", &pos);

                insert(value, pos);
                break;

            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);

                deleteNode(pos);
                break;

            case 3:
                displayLeftToRight();
                break;

            case 4:
                displayRightToLeft();
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}