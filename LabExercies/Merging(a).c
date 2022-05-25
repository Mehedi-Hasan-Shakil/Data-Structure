//Add two integer type arrays
#include <stdio.h>
int main(void)
{
    int na = 5, nb = 5;
    int a[5] = {2, 5, 4, 3, 1};
    int b[5] = {9, 4, 5, 7, 6};
    int nc = na + nb;
    int c[nc];
    int k = 0; //index for new array
    for(int i = 0; i < na; i++)
    {
        c[k++] = a[i];
    }
    for(int i = 0; i < nb; i++)
    {
        c[k++] = b[i];
    }
    for(int i = 0; i < nc; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
}
