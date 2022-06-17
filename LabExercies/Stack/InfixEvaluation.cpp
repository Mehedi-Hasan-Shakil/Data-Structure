#include <bits/stdc++.h>
using namespace std;
bool isNumber(string);
void Print();
void InfixToPostfix();
float PostfixEvaluation();

char q[100], str[10];
string p[100];
int k = 0;

int main(void)
{
    scanf("%[^\n]", q);
    InfixToPostfix();
    Print();
    printf("Result = %.2f\n", PostfixEvaluation());
    return 0;
}


void InfixToPostfix() //convert infix to postfix
{
    char parenthesis[2] = ")";
    strcat(q, parenthesis);
    stack<char> st;
    st.push('(');
    int i = 0, j;
    while(!st.empty())
    {
        if(isdigit(q[i]) || q[i] == '.') //Check for digit, character by character
        {                                //including decimal point
            j = 0;
            while(isdigit(q[i]) || q[i] == '.')
            {
                str[j++] = q[i];
                i++;
                if(q[i] == '.')
                {
                    str[j++] = '.';
                    i++;
                }
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
}
float PostfixEvaluation()   //Evaluation of postfix notation
{
    float a, b, number;
    stack<float> st1;
    for(int i = 0; i < k; i++)
    {
        if(isNumber(p[i])) //Check if the string is number
        {
            istringstream(p[i]) >> number;
            st1.push(number);
        }
        else if(p[i] == "+")
        {
            a = st1.top();
            st1.pop();
            b = st1.top();
            st1.pop();
            st1.push(b + a);
        }
        else if(p[i] == "-")
        {
            a = st1.top();
            st1.pop();
            b = st1.top();
            st1.pop();
            st1.push(b - a);
        }
        else if(p[i] == "*")
        {
            a = st1.top();
            st1.pop();
            b = st1.top();
            st1.pop();
            st1.push(b * a);
        }
        else if(p[i] == "/")
        {
            a = st1.top();
            st1.pop();
            b = st1.top();
            st1.pop();
            st1.push(b / (float) a);
        }
        else if(p[i] == "^")
        {
            a = st1.top();
            st1.pop();
            b = st1.top();
            st1.pop();
            st1.push(pow(b, a));
        }
    }
    return st1.top();
}

bool isNumber(string s) //Check if the string is a number
{
    char c = s[0];
    if(c == '.' || (c >= '0' && c <= '9'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Print() //Print the postfix notation
{
    cout<<"Postfix Notation : ";
    for(int i = 0; i < k; i++)
    {
        cout<<p[i]<<" ";
    }
    printf("\n");
}
