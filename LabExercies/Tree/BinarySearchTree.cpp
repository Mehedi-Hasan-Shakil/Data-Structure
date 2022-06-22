#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
typedef Node node;
node *root = NULL, *ptr = NULL, *par = NULL;
int loc, c = 0;

void InsertElement();
node* CreateNode(int);
void Print_Inorder(node*);

int main(void)
{
    InsertElement();
    Print_Inorder(root);
    return 0;
}

node* CreateNode(int item)
{
    node *newNode = (node*)(malloc(sizeof(node)));
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void InsertElement()
{
    int item;
    cout<<"Enter an element : ";
    cin>>item;
    root = CreateNode(item);
    c++;
loop:
    loc = 1;
    ptr = root;
    while(ptr != NULL)
    {
        par = ptr;
        if(item < ptr->data)
        {
            loc = loc * 2;
            ptr = ptr->left;
        }
        else if(item > ptr->data)
        {
            loc = loc * 2 + 1;
            ptr = ptr->right;
        }
        else
        {
            if(c > 1)
                cout<<item<<" is found at location "<<loc<<"\n";
            break;
        }
    }
    if(item < par->data)
    {
        par->left = CreateNode(item);
    }
    else if(item > par->data)
    {
        par->right = CreateNode(item);
    }
    c++;
    cout<<"Enter another element : ";
    cin>>item;
    if(item != -1)
    {
        goto loop;
    }
}

void Print_Inorder(node *ptr1)
{
    if(ptr1 != NULL)
    {
        Print_Inorder(ptr1->left);
        cout<<ptr1->data<<" ";
        Print_Inorder(ptr1->right);
    }
}
