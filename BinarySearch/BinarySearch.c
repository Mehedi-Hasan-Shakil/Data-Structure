#include <stdio.h>

int main(void)
{
    int n = 10;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int beg = 0, end = n - 1,  mid = (beg + end) / 2;
    int item = 9;
    while(arr[mid] != item && beg <= end)
    {
        if(arr[mid] > item)
        {
            end = (mid - 1);
        }
        else if(arr[mid] < item)
        {
            beg = (mid + 1);
        }
        mid = (beg + end) / 2;
    }
    printf("%d is found at %d\n", item, mid);
    return 0;
}
