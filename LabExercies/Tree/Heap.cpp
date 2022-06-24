#include <bits/stdc++.h>
using namespace std;
void Insert(int);
void Print();
void PrintBinaryTree();
int n = 11, ptr, par;
int heap[15] = {-1, 50, 45, 43, 34, 30, 18, 29, 20, 25, 26, 28};
int main(void)
{
    cout<<"Enter an item : ";
    int item;
    cin>>item;
    Insert(item);
    PrintBinaryTree();
    Print();
    return 0;
}

void Insert(int item)
{
    n = n + 1;
    ptr = n;
    while(ptr > 1)
    {
        par = ptr / 2;
        if(item <= heap[par])
        {
            heap[ptr] = item;
            return;
        }
        heap[ptr] = heap[par];
        ptr = par;
    }
    heap[1] = item; //when item is larger than root
}

void Print()
{
    cout<<"\n\n";
    for(int  i = 1; i <= n; i++)
    {
        cout<<heap[i]<<" ";
    }
    cout<<"\n";
}

void PrintBinaryTree()
{
    int j = 0, isNewLine = 1; //variable j denotes the level
    for(int i = 1; i <= n; i++)
    {
        if(isNewLine) //When new line appears, spaces are reduced
            for(int k = i*5; k < 50; k++)
            {
                cout<<' ';
                isNewLine = 0;
            }
        cout<<heap[i]<<"\t";
        if((i+1)%(int)(pow(2,j)) == 0) // When we have i = 1, 3, 7, 15, ...
        {                              //new line is printed
            isNewLine = 1;
            j++;
            cout<<"\n";
        }
    }
}
