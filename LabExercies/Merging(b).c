//Add two character type arrays
#include <stdio.h>
int main(void)
{
    int na = 5, nb = 5;
    char a[5] = {'f', 'd', 'e', 'e', 'h'};
    char b[5] = {'c', 'n', 's', 'r', 'g'};
    int nc = na + nb;
    int k = 0, c[nc]; //k is for index for c
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
        printf("%c ", c[i]);
    }
    printf("\n");
}
