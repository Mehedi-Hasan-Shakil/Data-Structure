#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node node;

node *start = NULL, *ptr = NULL, *ptrp = NULL, *tmp = NULL;

node* CreateNode();
void AddNodeLast(int item);
void PrintLinkedList();
void Delete_Given_Node(int item);

int main(void)
{
    AddNodeLast(5);
    AddNodeLast(3);
    AddNodeLast(9);
    AddNodeLast(42);
    AddNodeLast(0);
    AddNodeLast(10);
    printf("Before deleting : ");
    PrintLinkedList();
    printf("After deleting : ");
    Delete_Given_Node(0);
    PrintLinkedList();
}

node* CreateNode()
{
    node *tmp = NULL;
    tmp = (node *)malloc(sizeof(node));
    return tmp;
};
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

void AddNodeLast(int item)   //Add node at the end of the LinkedList
{
    node *tmp = NULL;
    tmp = CreateNode();
    tmp->data = item;
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
void Delete_Given_Node(int item)
{
    if(start == NULL) //When the list is empty
    {
        printf("Under flow.\n\n");
        return;
    }
    if(start->data == item) //When first element is equal to item
    {
        tmp = start;
        start = start->link;
        free(tmp);
        return;
    }
    ptr = start;
    ptrp = start;
    while(ptr != NULL)
    {
        if(ptr->data == item)
        {
            tmp = ptr;
            ptrp->link = tmp->link;
            free(tmp);
            return;
        }
        ptrp = ptr;
        ptr = ptr->link;
    }
    printf("Item not found. ");
}
