#include <stdio.h>

int main(void)
{
    char str[] = "PEOPLE";
    int n = 6;
    int interchange = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n - i; j++)
        {
            if(str[j] > str[j + 1])
            {
                char tmp = str[j + 1];
                str[j + 1] = str[j];
                str[j] = tmp;
                interchange++;
            }
        }
    }
    printf("Number of comparisons %d\nNumber of interchange %d\n", n * (n - 1) / 2, interchange);
    printf("The word after sorting is %s\n", str);
    return 0;
}
