#include <stdio.h>
#include <math.h>
int main(void)
{
    int n = 10;
    int array[10] = {3, 4, 2, 6, 16, 9, 5, 8, 1, 7};
    int maximum = array[0], minimum = array[0], sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(array[i] > maximum)
        {
            maximum = array[i];
        }
        if(array[i] < minimum)
        {
            minimum = array[i];
        }
        sum = sum + array[i];
        printf("sin(%d) = %.2f\n", array[i], sin(array[i]));
    }
    printf("Maximum value is %d\n", maximum);
    printf("Minimum value is %d\n", minimum);
    printf("Average value is %.2f\n", sum / (float) n);
    printf("Total Value is %d\n", sum);
}
