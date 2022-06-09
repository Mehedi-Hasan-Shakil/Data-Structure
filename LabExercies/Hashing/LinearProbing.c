#include <stdio.h>

int a[11];
int n = 11;

void add(int);
void Print();

int main(void)
{
    for(int i = 0; i < n; i++)
    {
        a[i] = -1;
    }
    add(11);
    add(12);
    add(13);
    add(43);
    add(22);
    add(115);
    add(110);
    add(44);
    Print();
}

void add(int item)
{
    int index = item % n;
    if(a[index] == -1)
    {
        a[index] = item;
    }
    else
    {
        int start = index;
        for(int j = (index + 1) % n; j != start; j = (j + 1) % n)
        {
            if(a[j] == -1)
            {
                a[j] = item;
                break;
            }
        }
    }
}

void Print()
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");
}
