#include <stdio.h>
int Fact_Iterative(int);
int Fact_Recursion(int);
int main(void)
{
    int n;
    printf("Enter your number : ");
    scanf("%d", &n);
    printf("Factorial of %d is %d\n", n, Fact_Recursion(n));
}

int Fact_Iterative(int n) //Factorial using iteration
{
    if(n == 0)
    {
        return 1;
    }
    int fact = 1;
    for(int  i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}
int Fact_Recursion(int n)   //Factorial using recursion
{
    if(n == 0)
    {
        return 1;
    }
    else
        return n * Fact_Recursion(n-1);

}
