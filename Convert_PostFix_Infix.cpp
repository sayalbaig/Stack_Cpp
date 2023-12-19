#include <iostream>
#include <stack>
using namespace std;

int precedence(char temp)
{
    if (temp == '+' || temp == '-')
        return 1;
    else if (temp == '*' || temp == '/')
        return 2;
    else if (temp == '^')
        return 3;
    else if (temp == '(' || temp == ')')
        return -1;

    return 0;
}
string postfixtoinfex(string postfix)
{
    stack<string> st;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (precedence(postfix[i]) == 0)
        {
            string op(1, postfix[i]);
            st.push(op);
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string exp = '(' + op2 + postfix[i] + op1 + ')';
            st.push(exp);
        }
    }
    return st.top();
}
int main()
{
    string s = postfixtoinfex("ab+c-def^^*g/");
    cout<<s;
}
