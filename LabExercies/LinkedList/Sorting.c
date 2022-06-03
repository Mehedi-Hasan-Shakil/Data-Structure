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
void PrintLinkedList();
void Selection_Sort();
void Bubble_Sort();

node *start = NULL, *ptr = NULL,  *tmp = NULL, *ptrp = NULL;

int main(void)
{
    AddNodeLast(300);
    AddNodeLast(9);
    AddNodeLast(5);
    AddNodeLast(1111);
    AddNodeLast(22);
    AddNodeLast(20);
    printf("Before sorting : ");
    PrintLinkedList();
    //Selection_Sort();
    //printf("After selection sorting : ");
    Bubble_Sort();
    printf("After bubble sort : ");
    PrintLinkedList();
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

void Selection_Sort()   //Selection sort algorithm
{
    int temp;
    ptrp = start;
    while(ptrp->link != NULL)
    {
        ptr = ptrp->link;
        while(ptr != NULL)
        {
            if(ptrp->data > ptr->data)
            {
                tmp = ptrp->data;
                ptrp->data = ptr->data;
                ptr->data = tmp;
            }
            ptr = ptr->link;
        }
        ptrp = ptrp->link;
    }
}
void Bubble_Sort()   //Bubble sort
{
    int temp;
    node *end = NULL;
    while(end != start->link)
    {
        ptrp = start;
        ptr = start->link;
        while(ptr != end)
        {
            if(ptrp->data > ptr->data)
            {
                temp = ptrp->data;
                ptrp->data = ptr->data;
                ptr->data = temp;
            }
            ptrp = ptrp->link;
            ptr = ptr->link;
        }
        end = ptrp;
    }


}
