#include <iostream>
#include <stack>
#include <algorithm>
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
void revBrackets(string &infix)
{
    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }
    return;
}
string infixToprefix(string infix)
{
    string prefix;
    stack<char> st;
    reverse(infix.begin(), infix.end());
    revBrackets(infix);
    for (int i = 0; i < infix.length(); i++)
    {
        if (precedence(infix[i]) == 0)
        {
            prefix += infix[i];
        }
        else if (infix[i] == '(')
        {
            st.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (st.top() != '(' && !st.empty())
            {
                prefix += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (infix[i] != 0 && infix[i] != -1)
        {
            if (st.empty())
            {
                st.push(infix[i]);
            }
            else
            {
                if (precedence(infix[i]) > precedence(st.top()))
                {
                    st.push(infix[i]);
                }
                else if (precedence(infix[i]) == precedence(st.top()) && infix[i] == '^')
                {
                    while (precedence(infix[i]) == precedence(st.top()) && infix[i] == '^')
                    {
                        prefix += st.top();
                        st.pop();
                    }
                    st.push(infix[i]);
                }
                else if (precedence(infix[i]) == precedence(st.top()))
                {
                    st.push(infix[i]);
                }
                else 
                {
                    while (!st.empty() && precedence(infix[i]) < precedence(st.top()))
                    {
                        prefix += st.top();
                        st.pop();
                    }
                    st.push(infix[i]);
                }
            }
        }

    }
    while (!st.empty())
    {
        prefix += st.top();
        st.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}
int main()
{
    string s = infixToprefix("((a+b-c)*d^e^f)/g");
    cout<<s;
    return 0;
}
