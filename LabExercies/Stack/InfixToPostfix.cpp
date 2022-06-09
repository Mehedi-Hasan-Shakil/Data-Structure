#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    char q[100], str[10];
    string p[100];
    scanf("%[^\n]", q);
    char parenthesis[2] = ")";
    strcat(q, parenthesis);
    stack<char> st;
    st.push('(');
    int number, i = 0, j, k = 0;
    while(!st.empty())
    {
        if(isdigit(q[i]))
        {
            j = 0;
            while(isdigit(q[i]))
            {
                str[j++] = q[i];
                i++;
            }
            i--;
            str[j] = '\0';
            p[k++] = str;
        }
        else if(q[i] == '(')
        {
            st.push('(');
        }
        else if(q[i] == '+')
        {
            while(st.top() == '+' || st.top() == '-' || st.top() == '/' || st.top() == '*' || st.top() == '^')
            {
                p[k++] = st.top();
                st.pop();
            }
            st.push('+');
        }
        else if(q[i] == '-')
        {
            while(st.top() == '+' || st.top() == '-' || st.top() == '/' || st.top() == '*' || st.top() == '^')
            {
                p[k++] = st.top();
                st.pop();
            }
            st.push('-');
        }
        else if(q[i] == '*')
        {
            while(st.top() == '/' || st.top() == '*' || st.top() == '^')
            {
                p[k++] = st.top();
                st.pop();
            }
            st.push('*');
        }
        else if(q[i] == '/')
        {
            while(st.top() == '/' || st.top() == '*' || st.top() == '^')
            {
                p[k++] = st.top();
                st.pop();
            }
            st.push('/');
        }
        else if(q[i] == '^')
        {
            while(st.top() == '^')
            {
                p[k++] = st.top();
                st.pop();
            }
            st.push('^');
        }
        else if(q[i] == ')')
        {
            while(st.top() != '(')
            {
                p[k++] = st.top();
                st.pop();
            }
            st.pop();
        }
        i++;
    }
    for(int i = 0; i < k; i++)
    {
        cout<<p[i]<<" ";
    }
}
