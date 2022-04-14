#include <stdio.h>

int main(void)
{
    int n = 10;
    int DATA[] = {3, 2, 4, 1, 8, 9, 5, 7, 6, 3};
    for(int k = 1; k <= n - 1; k++)   //here k is not used as index
    {
        for(int j = 0; j < n - k; j++)
        {
            if(DATA[j] > DATA[j + 1])
            {
                int tmp;
                tmp = DATA[j];
                DATA[j] = DATA[j + 1];
                DATA[j + 1] = tmp;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d ", DATA[i]);
    }
    printf("\n");
    return 0;
}
