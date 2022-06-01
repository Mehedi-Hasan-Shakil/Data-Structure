#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
typedef struct Node node;

node* CreateNode();
void AddNodeLast(int info);
void AddNodeFirst(int item);
void After_Given_Node(int Given_Node, int item);
void Insert_Sorted_List(int item);
void PrintLinkedList();

node *start = NULL, *ptr = NULL,  *tmp = NULL, *ptrp = NULL;

int main(void)
{
    AddNodeLast(3);
    AddNodeLast(5);
    AddNodeLast(9);
    AddNodeLast(11);
    AddNodeLast(20);
    AddNodeLast(22);

    /*printf("Before adding : ");
    PrintLinkedList();
    Insert_Sorted_List(21);
    printf("After adding : ");
    PrintLinkedList();*/

    printf("Before adding : ");
    PrintLinkedList();
    After_Given_Node(20, 21);
    printf("After adding : ");
    PrintLinkedList();

    /*printf("List before adding node at beginning : ");
    PrintLinkedList();
    AddNodeFirst(15);
    printf("List after adding node at beginning : ");
    PrintLinkedList();*/
}

void AddNodeLast(int info) //Insert item at the end of the list
{
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

void AddNodeFirst(int item) //Insert item beginning of the list
{
    tmp = CreateNode();
    tmp->data = item;
    tmp->link = start;
    start = tmp;
}

void After_Given_Node(int Given_Node, int item) //Insert item after a given node
{
    tmp = CreateNode();
    tmp->data = item;
    tmp->link = NULL;
    if(start == NULL)
    {
        start = tmp;
        return;
    }
    ptr = start;
    while(ptr != NULL)
    {
        if(ptr->data == Given_Node)
        {
            tmp->link = ptr->link;
            ptr->link = tmp;
            return;
        }
        ptr = ptr->link;
    }
    tmp->link = start;
    start = tmp;
}

node* CreateNode()
{
    tmp = (node *)malloc(sizeof(node));
    return tmp;
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

void Insert_Sorted_List(int item) //Insert item into a sorted list
{
    tmp = CreateNode();
    tmp->data = item;
    tmp->link = NULL;

    if(start == NULL) //When the list is empty
    {
        start = tmp;
        return;
    }
    if(item <= start->data) //When item is smaller than first element
    {
        tmp->link = start;
        start = tmp;
        return;
    }
    ptr = start;
    while(ptr != NULL)
    {
        if(item < ptr->data) //Inside the list
        {
            ptrp->link = tmp;
            tmp->link = ptr;
            return;
        }
        ptrp = ptr;
        ptr = ptr->link;
    }
    ptrp->link = tmp; //When item is larger than last element
    tmp->link = NULL;
}
