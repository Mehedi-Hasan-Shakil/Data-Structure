//Copy from 2D to 1D array
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int row = 4, column = 9;
    string member2D[4][9] = {{"Evans", "Harris", "Lewis", "Shaw"},
                             {"Conrad", "Felt", "Glass", "Hill", "King", "Penn", "Silver", "Troy", "Wagner"},
                             {"Davis", "Segal"},
                             {"Baker", "Cooper", "Ford", "Gray", "Jones", "Reed"}};
    string member1D[32];
    int n = 32;
    int group[4] = {1, 7, 19, 23};
    int number[4] = {4, 9, 2, 6};
    int free[4] = {2, 3, 2, 4};
    int k = 0;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < number[i]; j++)
        {
            member1D[k++] = member2D[i][j];
        }
        k = k + free[i];
    }
    for(int i = 0; i < n; i++)
    {
        cout<<member1D[i]<<"\n";
    }
}
