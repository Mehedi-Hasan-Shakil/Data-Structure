#include <stdio.h>
void insert_linear_probing(int);
void insert_plus3_probing(int);
void insert_quadratic_probing(int);
void Print();
int n = 11;
int a[11];
int main(void)
{
    for(int i = 0; i < n; i++)
    {
        a[i] = -1;
    }
    insert_quadratic_probing(11);
    insert_quadratic_probing(12);
    insert_quadratic_probing(23);
    insert_quadratic_probing(34);
    insert_quadratic_probing(34);
    Print();
}

void Print() {
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");
}
void insert_linear_probing(int item)
{
    int index = item % n;
    if(a[index] == -1)
    {
        a[index] = item;
    }
    else
    {
        int start = index;
        index = (index + 1) % n;

        for(int j = index; j != start; j = (j + 1) % n)
        {
            if(a[j] == -1)
            {
                a[j] = item;
                break;
            }
        }
    }
}

void insert_plus3_probing(int item)
{
    int index = item % n;
    if(a[index] == -1)
    {
        a[index] = item;
    }
    else
    {
        int start = index;
        index = (index + 3) % n;

        for(int j = index; j != start; j = (j + 3) % n)
        {
            if(a[j] == -1)
            {
                a[j] = item;
                break;
            }
        }
    }
}

void insert_quadratic_probing(int item) {
    int index = item % n;
    if(a[index] == -1)
    {
        a[index] = item;
    }
    else
    {
        int k = 1;
        int start = index;
        index = (index + k * k) % n;

        for(int j = index; j != start; j = (start + k * k) % n)
        {
            if(a[j] == -1)
            {
                a[j] = item;
                break;
            }
            k++;
        }
    }
}
