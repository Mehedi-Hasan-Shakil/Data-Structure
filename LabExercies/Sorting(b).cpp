//Sort string data using Bubble sort
#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int n = 10;
    string names[10] = {"Bashar", "Liton", "Mashrafe", "Anamul", "Sakib", "Taijul", "Aftab", "Razzak", "Mustafiz", "Rubel"};
    for(int  i = 1; i < n; i++) {
        for(int k = 0; k < n - i; k++) {
            if(names[k].compare(names[k + 1]) > 0) {
                string tmp = names[k];
                names[k] = names[k + 1];
                names[k + 1] = tmp;
            }
        }
    }
    for(string s : names) {
        cout<<s<<"\n";
    }
}
