//Inserting Karim to position 5
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n = 9;
    string names[10] = {"Anamul", "Bashar", "Mashrafe", "Sakib", "Taijul", "Aftab", "Razzak", "Mustafiz", "Rubel"};
    string person = "Karim";
    int insertion_position = 4;
    for(int i = n - 1; i >= insertion_position; i--)
    {
        names[i + 1] = names[i];
    }
    names[insertion_position] = person;
    n = n + 1;
    for(string s : names)
    {
        cout<<s<<" ";
    }
    cout<<"\n";
}
