//Search for 77 using binary search
#include <stdio.h>
int main(void)
{
    int n = 10;
    int data[10] = {34, 37, 39, 40, 46, 47, 52, 53, 77, 87};
    int item = 77;
    int beg = 0, end = n - 1;
    int mid = (beg + end) / 2;
    while(beg <= end && item != data[mid])
    {
        if(item < data[mid])
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
        mid = (beg + end) / 2;
    }
    if(data[mid] == item)
    {
        printf("Found at position %d\n", mid + 1);
    }
    else
    {
        printf("Not found\n");
    }
}
