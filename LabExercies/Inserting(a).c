//Inserting 54 to a sorted array.
#include <stdio.h>
int main(void)
{
    int n = 9;
    int array[10] = {12, 15, 17, 24, 32, 65, 66, 70, 98};
    int item = 54;
    int i = 0;
    for(i; i < n; i++)
    {
        if(array[i] > item)
        {
            break;
        }
    }
    int insertion_position = i;
    for(int j = n - 1; j >= insertion_position; j--)
    {
        array[j + 1] = array[j];
    }
    array[insertion_position] = item;
    n = n + 1;
    for(int k = 0; k < n; k++)
    {
        printf("%d ", array[k]);
    }
    printf("\n");
}
