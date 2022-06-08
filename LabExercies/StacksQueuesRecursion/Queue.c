#include <stdio.h>
int n = 10;
int queue[10];
int front = -1, rear = -1;

void Queue_Insert(int);
int Queue_Delete();
void Print();
int  main(void)
{
    Queue_Insert(1);
    Queue_Insert(2);
    Queue_Insert(3);
    Queue_Insert(4);
    Queue_Insert(5);
    Queue_Insert(6);
    Queue_Insert(7);
    Queue_Insert(8);
    Queue_Insert(9);
    Queue_Insert(10);
    Print();
    Queue_Delete();
    Queue_Delete();
    Queue_Delete();
    Queue_Delete();
    Print();
    Queue_Insert(11);
    Queue_Insert(12);
    Print();
    Queue_Delete();
    Queue_Delete();
    Queue_Delete();
    Queue_Delete();
    Queue_Delete();
    Queue_Delete();
    Print();
    return 0;
}

void Queue_Insert(int item)
{
    if((front == 0 && rear == n-1) || (front == rear+1)) //When the queue is full
    {
        printf("Overflow\n");
    }
    else
    {
        if(front == -1) //When the queue is empty
        {
            front = 0;
            rear = 0;
        }
        else if(rear == n-1) //When rear is at last of the queue
        {
            rear = 0;
        }
        else //When front <= rear
        {
            rear++;
        }
        queue[rear] = item;
    }
}

int Queue_Delete()
{
    if(front == -1) //When the queue is empty
    {
        printf("Underflow");
    }
    else
    {
        int item = queue[front];
        if(front == rear) //When there is only one element
        {
            front = -1;
            rear = -1;
        }
        else if(front == n-1) //When front is at last of the queue
        {
            front = 0;
        }
        else //When front < rear
        {
            front++;
        }
        return item;
    }
}
void Print()
{
    printf("Front = %d Rear = %d\n", front+1, rear+1);
    if(front <= rear)
    {
        for(int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    else
    {
        for(int i = front; i < n; i++)
        {
            printf("%d ", queue[i]);
        }
        for(int i = 0; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    printf("\n\n");
}
