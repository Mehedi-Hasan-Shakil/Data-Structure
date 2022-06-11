//Find the value of an Arithmetic expression P written in postfix notation
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int number, a, b;
    stack<int> st;
    char p[100];
    scanf("%[^\n]", p);
    char parenthesis[2] = ")";
    strcat(p, parenthesis);
    for(int i = 0; p[i] != ')'; i++)
    {
        if(isdigit(p[i]))
        {
            number = 0;
            while(isdigit(p[i]))
            {
                number = number*10 + (p[i] - '0');
                i++;
            }
            i--;
            st.push(number);
        }
        else if(p[i] == '+')
        {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b + a);
        }
        else if(p[i] == '-')
        {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b - a);
        }
        else if(p[i] == '*')
        {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b * a);
        }
        else if(p[i] == '/')
        {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b / a);
        }
        else if(p[i] == '^')
        {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(pow(b, a));
        }
    }
    cout<<st.top()<<" ";
    st.pop();
    return 0;
}
