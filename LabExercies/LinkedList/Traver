#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node node;

node *start = NULL, *ptr = NULL;
void Traversing();
void AddNodeLast(int info);
node* CreateNode();

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

    Traversing();
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

void Traversing()
{
    ptr = start;
    int sum = 0, n = 0, min = start->data, max = start->data;
    printf("\nThe sin values are : ");
    while(ptr != NULL)
    {
        n++;
        sum = sum + ptr->data;
        if(ptr->data > max)
            max = ptr->data;
        else if(ptr->data < min)
            min = ptr->data;
        printf("%.2f ", sin(ptr->data));
        ptr = ptr->link;
    }
    printf("\n\nMaximum value is %d\n", max);
    printf("\nMinimum value is %d\n", min);
    printf("\nAverage value is %.2f\n", sum / (float) n);
    printf("\nTotal value is %d\n", sum);
}
