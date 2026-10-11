#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;  };

struct Node *head = NULL;

void insertBeginning(int value)
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
        newNode->next = head;
        temp->next = newNode;
        head = newNode;    }
    printf("%d inserted at beginning\n", value);
}

void insertEnd(int value)
{
    struct Node *newNode,*temp;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL)
    {
        head=newNode;
        newNode->next=head;
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
    printf("%d inserted at end\n", value);
}

void insertAfter(int key, int value)
{
    struct Node *temp, *newNode;
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
            newNode = (struct Node *)malloc(sizeof(struct Node));

            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;

            printf("%d inserted after %d\n", value, key);
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
        temp = temp->next; }
     while (temp != head);
    printf("(HEAD)\n");
}
int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    display();

    insertBeginning(5);
    display();

    insertAfter(20, 25);
    display();
    return 0;
}