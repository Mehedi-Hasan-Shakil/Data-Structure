/*Write a procedure FIND(DATA, N, LOC1, LOC2) which finds
largest and second largest element and
the location LOC1 of the largest element and the location
LOC2 of the second largest element in an array DATA with n
> 1 elements.*/
#include <stdio.h>

int main()
{
    int arr[] = {3, 9, 2, 4, 7};
    int largest = arr[0], slargest = arr[0], LOC1 = 0, LOC2 = 0;
    for(int i = 1; i < 5; i++)
    {
        if(largest < arr[i])
        {
            slargest = largest; //When a largest element is found, the previous
            largest = arr[i];   //largest element is transfered to the second
            LOC2 = LOC1;        //largest variable as well as its location
            LOC1 = i;
        }
        else if(slargest < arr[i])
        {
            slargest = arr[i];  //Checks for second largest element only
            LOC2 = i;
        }
    }
    printf("Largest = %d Second Largest = %d\n", largest, slargest);
    printf("Largest LOC = %d Second Largest LOC = %d\n", LOC1, LOC2);
    return 0;
}
