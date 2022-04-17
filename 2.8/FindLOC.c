/*Write a procedure FIND(DATA, N, LOC1, LOC2) which finds
largest and second largest element and
the location LOC1 of the largest element and the location
LOC2 of the second largest element in an array DATA with n
> 1 elements.*/
#include <stdio.h>

int main()
{
    int arr[] = {3, 9, 3, 4, 7};
    int largest = arr[0], slargest = arr[1], LOC1 = 0, LOC2 = 1;
    if(slargest > largest) {
        int tmp = largest;
        largest = slargest;
        slargest = tmp;
        tmp = LOC1;
        LOC1 = LOC2;
        LOC2 = tmp;
    }
    for(int i = 2; i < 5; i++)
    {
        if(largest < arr[i])
        {
            slargest = largest;
            largest = arr[i];
            LOC2 = LOC1;
            LOC1 = i;
        }
        else if(slargest < arr[i])
        {
            slargest = arr[i];
            LOC2 = i;
        }
    }
    printf("Largest = %d Second Largest = %d\n", largest, slargest);
    printf("Largest LOC = %d Second Largest LOC = %d\n", LOC1, LOC2);
    return 0;
}
