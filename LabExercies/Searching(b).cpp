//Search for Karim using binary search
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n = 10;
    string data[10] = {"Aftab", "Bashar", "Karim", "Liton", "Mashrafe", "Mustafiz", "Razzak", "Rubel", "Sakib", "Taijul"};
    string person = "Karim";
    int beg = 0, end = n - 1;
    int mid = (beg + end) / 2;
    while(beg <= end && person.compare(data[mid]))
    {
        if(person.compare(data[mid]) < 0)
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
        mid = (beg + end) / 2;
    }
    if(person.compare(data[mid]) == 0)
    {
        cout<<"Found at position "<<mid + 1<<"\n";
    }
    else
    {
        cout<<"Not found\n";
    }
}
