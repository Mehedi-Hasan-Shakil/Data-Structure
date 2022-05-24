//Sort integer data using Bubble sort
#include <stdio.h>
int main(void)
{
    int n = 10;
    int data[10] = {5, 4, 7, 6, 34, 8, 3, 9, 2, 1};
    for(int i = 1; i < n; i++)
    {
        for(int k = 0; k < n - i; k++)
        {
            if(data[k] > data[k + 1])
            {
                int tmp = data[k];
                data[k] = data[k + 1];
                data[k + 1] = tmp;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
}
