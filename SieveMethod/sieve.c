#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int  n;
    cin>>n;
    vector<int> arr;
    for (int i = 1; i <= n; i++)
    {
        arr.push_back(i);
    }
    for (int i = 2; i * i <= n; i++)
    {
        for (int j = (2 * i) - 1; j <= n; j = j + i)
        {
            if (arr[j] != 1)
            {
                arr[j] = 1;
            }
        }
    }

    int count = remove(arr.begin(), arr.end(), 1) - arr.begin();
    for(int i = 0; i < count; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
