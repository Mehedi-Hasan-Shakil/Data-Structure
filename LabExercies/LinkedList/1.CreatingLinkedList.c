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

node *start = NULL, *ptr = NULL,  *tmp = NULL;

int main(void)
{
    AddNodeLast(5);
    AddNodeLast(3);
    AddNodeLast(9);
    AddNodeLast(42);
    AddNodeLast(0);
    AddNodeLast(10);
    ptr = start;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void AddNodeLast(int info)
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
