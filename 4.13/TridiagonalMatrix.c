#include <stdio.h>

int main(void)
{
    int la[] = {1, 2, 3, 4, 5, 6, 7};
    int j, k;
    printf("Enter j and k : ");
    scanf("%d%d", &j, &k);
    printf("Element at [%d, %d] is %d\n", j, k, la[2 * j + k]);
    return 0;
}
