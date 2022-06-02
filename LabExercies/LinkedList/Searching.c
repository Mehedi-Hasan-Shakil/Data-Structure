#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node node;

node *start = NULL, *ptr = NULL;

int Searching(int item);
void AddNodeLast(int info);
node* CreateNode();
void PrintLinkedList();

int main(void)
{
    /*AddNodeLast(5);
    AddNodeLast(3);
    AddNodeLast(9);
    AddNodeLast(42);
    AddNodeLast(0);
    AddNodeLast(10);*/
    int position = Searching(5);
    if(position == -1)
    {
        printf("Underflow.\n\n");
    }
    else if(position > 0)
    {
        printf("Found at position %d\n\n", position);
    }
    else
    {
        printf("Not found.\n\n");
    }
    PrintLinkedList();
}

void AddNodeLast(int info)   //Add node at the end of the LinkedList
{
    node *tmp = NULL;
    tmp = CreateNode();
    tmp->data = info;
    tmp->link = NULL;
    if(start == NULL)
    {
        start = tmp;
        ptr = tmp;
    }
    else
    {
        ptr->link = tmp;
        ptr = tmp;
    }
}

node* CreateNode()
{
    node *tmp = NULL;
    tmp = (node *)malloc(sizeof(node));
    return tmp;
};

int Searching(int item)
{
    if(start == NULL)
    {
        return -1;
    }
    ptr = start;
    int count = 0;
    while(ptr != NULL)
    {
        count++;
        if(ptr->data == item)
        {
            return count;
        }
        ptr = ptr->link;
    }
    return 0;
}

void PrintLinkedList() //Print the list
{
    ptr = start;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n\n");
}
