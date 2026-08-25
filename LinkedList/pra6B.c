#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertEnd(int value)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void deleteFirst()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    printf("%d deleted from beginning\n", temp->data);

    free(temp);
}

void deleteLast()
{
    struct Node *temp;
    struct Node *prev;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL)
    {
        printf("%d deleted from end\n", head->data);

        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    printf("%d deleted from end\n", temp->data);

    free(temp);
}

void deleteAfter(int key)
{
    struct Node *temp;
    struct Node *deleteNode;

    temp = head;

    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Node not found or no node after it\n");
        return;
    }

    deleteNode = temp->next;
    temp->next = deleteNode->next;

    printf("%d deleted after %d\n", deleteNode->data, key);

    free(deleteNode);
}

void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice, value, key;

    /* Initial nodes */
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    while (1)
    {
        printf("\n--- DELETE MENU ---\n");
        printf("1. Delete First Node\n");
        printf("2. Delete Last Node\n");
        printf("3. Delete Node After Given Node\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                deleteFirst();
                break;

            case 2:
                deleteLast();
                break;

            case 3:
                printf("Enter node value after which to delete: ");
                scanf("%d", &key);
                deleteAfter(key);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}