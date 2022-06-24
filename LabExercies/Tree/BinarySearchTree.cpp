#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
typedef Node node;
node *root = NULL, *ptr = NULL;
int loc;
void Insert();
void Print(node*, int);
node* CreatNode(int);
void Print_Inorder(node*);

int main(void)
{
    Insert();
    Print_Inorder(root);
    return 0;
}

node* CreatNode(int item)
{
    node *newNode = (node*)(malloc(sizeof(node)));
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void Insert()
{
    cout<<"Enter an element : ";
    int item;
    cin>>item;
    if(root == NULL)
    {
        root = CreatNode(item);
    }
    else
    {
loop:
        loc = 1;
        ptr = root;
        while(ptr != NULL)
        {
            if(item < ptr->data)
            {
                if(ptr->left == NULL)
                {
                    ptr->left = CreatNode(item);
                    ptr = ptr->left;
                }
                loc = loc * 2;
                ptr = ptr->left;
            }
            else if(item > ptr->data)
            {
                if(ptr->right == NULL)
                {
                    ptr->right = CreatNode(item);
                    ptr = ptr->right;
                }
                loc = loc * 2 + 1;
                ptr = ptr->right;
            }
            else
            {
                cout<<item<<" is found at location "<<loc<<"\n";
                break;
            }
        }
    }
    Print(root, 0);
    cout<<"Enter another element : ";
    cin>>item;
    if(item != -1) //Tree terminates when -1 is the input
        goto loop;
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

void Print(node *ptr1, int space)
{
    int increase = 10;
    if(ptr1 == NULL)
    {
        return;
    }
    space = space + increase;
    Print(ptr1->right, space); //Goes to the top right node
    cout<<"\n";
    for (int i = increase; i < space; i++)
    {
        cout << ' ';
    }
    cout<<ptr1->data;
    cout<<"\n";
    Print(ptr1->left, space);
}
