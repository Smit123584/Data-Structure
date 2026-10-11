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
    struct Node *newNode, *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }
}

void deleteFirst()
{
    struct Node *temp, *last;
    if (head == NULL)  {
        printf("List is empty\n");
        return;   
     }
    if (head->next == head)
    {
        printf("%d deleted\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    last = head;
    while (last->next != head)
    {
        last = last->next;
    }
    temp = head;
    head = head->next;
    last->next = head;

    printf("%d deleted from beginning\n", temp->data);
    free(temp);
}
    void deleteLast()
{
    struct Node *temp, *prev;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (head->next == head)
    {
        printf("%d deleted\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    temp = head;

    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    printf("%d deleted from end\n", temp->data);
    free(temp);
}

void deleteAfter(int key)
{
    struct Node *temp, *deleteNode;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = head;
    do
    {
        if (temp->data == key)
        {
            deleteNode = temp->next;

            if (deleteNode == head)
            {
                printf("No node after given node\n");
                return;
            }
            temp->next = deleteNode->next;
            printf("%d deleted after %d\n",deleteNode->data, key);
            free(deleteNode);
            return;
        }

        temp = temp->next; }
         while (temp != head);

         printf("Node not found\n");
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
    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;

    } while (temp != head);

    printf("(HEAD)\n");
}

int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    display();

    deleteFirst();
    display();

    deleteLast();
    display();

    deleteAfter(20);
    display();

    return 0;
}