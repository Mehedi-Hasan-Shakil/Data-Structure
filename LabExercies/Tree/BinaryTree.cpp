#include <bits/stdc++.h>
using namespace std;
struct Binary_Tree_Node
{
    int data;
    struct Binary_Tree_Node *left;
    struct Binary_Tree_Node *right;
};
typedef struct Binary_Tree_Node node;
node *root = NULL, *ptr = NULL;
int FIRST = 1;
stack<node*> st;

node* Create_Node();
void Print_Preorder();
void Print_Postorder(node*);
void Print_Inorder(node*);

int main(void)
{
    root = Create_Node();
    Print_Preorder();
    cout<<"\nPost-order : ";
    Print_Postorder(root);
    cout<<"\nInorder : ";
    Print_Inorder(root);
    cout<<"\n";
}

node* Create_Node()
{
    int info;
    if(FIRST)
    {
        printf("Enter your root node : ");
        FIRST = 0;
    }
    scanf("%d", &info);
    node *newNode;
    newNode = (node*)(malloc(sizeof(node)));
    if(info == -1)
    {
        return NULL;
    }
    newNode->data = info;
    printf("Enter left child of %d : ", info);
    newNode->left = Create_Node();
    printf("Enter right child of %d : ", info);
    newNode->right = Create_Node();
    return newNode;
}
void Print_Preorder()
{
    cout<<"\nPre-order : ";
    st.push(NULL);
    ptr = root;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        if(ptr->right != NULL)
        {
            st.push(ptr->right);
        }
        if(ptr->left != NULL)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = st.top();
            st.pop();
        }
    }
}

void Print_Postorder(node *ptr1)
{
    if(ptr1 != NULL)
    {
        Print_Postorder(ptr1->left);
        Print_Postorder(ptr1->right);
        cout<<ptr1->data<<" ";
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
