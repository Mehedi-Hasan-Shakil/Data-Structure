#include <stdio.h>
void Tower_Of_Hanoi(int, char[], char[], char[]);
int main(void)
{
    int n;
    printf("Enter number of disk : ");
    scanf("%d", &n);
    Tower_Of_Hanoi(n, "beg", "aux", "end");
    return 0;
}

void Tower_Of_Hanoi(int n, char beg[], char aux[], char end[])
{
    if(n == 1)
    {
        printf("Move from %s to %s\n", beg, end);
    }
    else
    {
        Tower_Of_Hanoi(n-1, beg, end, aux);
        Tower_Of_Hanoi(1, beg, aux, end);
        Tower_Of_Hanoi(n-1, aux, beg, end);
    }
}
