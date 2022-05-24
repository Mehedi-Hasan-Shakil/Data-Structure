//Inserting Rahim to a sorted array.
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n = 4;
    string names[5] = {"Anamul", "Mashrafe", "Sakib", "Taijul"};
    string person = "Rahim";
    int i = 0;
    for(i; i < n; i++)
    {
        if(names[i].compare(person) > 0)
        {
            break;
        }
    }
    int insertion_position = i;
    for(int j = n - 1; j >= insertion_position; j--)
    {
        names[j + 1] = names[j];
    }
    names[insertion_position] = person;
    n = n + 1;
    for(int j = 0; j < n; j++)
    {
        cout<<names[j]<<"\n";
    }
}
