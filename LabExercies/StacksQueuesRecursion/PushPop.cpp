#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main(void)
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(5);
    st.push(6);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
    return 0;
}
