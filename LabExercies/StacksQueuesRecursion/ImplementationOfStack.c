#include <stdio.h>
void push(int item);
int pop();
int isEmpty();
int isFull();

int max = 10;
int stack[10];
int top = -1;

int main(void)
{
    push(1);
    push(2);
    push(3);
    push(4);
    while(!isEmpty())
    {
        printf("%d ", pop());
    }
    printf("\n");
}

int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if(top == max - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int item)
{
    if(!isFull())
    {
        top++;
        stack[top] = item;
    }
    else
    {
        printf("Overflow.");
    }
}

int pop()
{
    if(!isEmpty())
    {
        int item = stack[top];
        top--;
        return item;
    }
    else
    {
        printf("Underflow");
    }
}
