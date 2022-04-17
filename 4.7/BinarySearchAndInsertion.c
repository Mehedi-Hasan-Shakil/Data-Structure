#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[7] = {1, 2, 3, 5, 6, 7};
    int n = 7;
    int item = 4;
    int loc;
    int beg = 0, end = 5, mid = (beg + end) / 2;
    while(beg <= end && arr[mid] != item)
    {
        if(item > arr[mid])
            beg = mid + 1;
        else
            end = mid - 1;
        mid = (beg + end) / 2;
    }
    if(item == arr[mid])
    {
        printf("%d is at index %d\n", item, mid);
        exit(0);
    }
    else
    {
        printf("%d is not found. Array after insertion %d is\n", item, item);
        if(item < arr[mid])
        {
            loc = mid;
        }
        else
        {
            loc = mid + 1;
        }
        for(int i = n - 2; i >= loc; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[loc] = item;
        for(int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
