#include <stdio.h>
int Fibonacci(int);
int main(void)
{
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);
    printf("f(%d) is %d\n", n, Fibonacci(n));
}

int Fibonacci(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}
