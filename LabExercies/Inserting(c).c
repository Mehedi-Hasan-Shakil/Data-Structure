//Inserting 99 to position 5
#include <stdio.h>
int main(void)
{
    int n = 9;
    int array[10] = {12, 35, 43, 34, 65, 89, 23, 64, 82};
    int item = 99;
    int insertion_position = 4;
    for(int i = n - 1; i >= insertion_position; i--)
    {
        array[i + 1] = array[i];
    }
    array[insertion_position] = item;
    n = n + 1;
    for(int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
