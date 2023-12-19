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

string infixTopostfix(string infix)
{
    string postfix;
    stack<char> st;
    for (int i = 0; i < infix.size(); i++)
    {
        if (precedence(infix[i]) == 0)
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            st.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (precedence(infix[i]) != 0 && precedence(infix[i]) != -1)
        {
            if (st.empty())
            {
                st.push(infix[i]);
            }
            else if (!st.empty())
            {
                if (precedence(infix[i]) > precedence(st.top()))
                {
                    st.push(infix[i]);
                }
                else if (precedence(infix[i]) == precedence(st.top()) && infix[i] == '^')
                {
                    st.push(infix[i]);
                }
                else
                {
                    while (!st.empty() && precedence(infix[i]) <= precedence(st.top()))
                    {
                        postfix += st.top();
                        st.pop();
                    }
                    st.push(infix[i]);
                }
            }
        }
    }
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main()
{
    string s = infixTopostfix("((a+b-c)*d^e^f)/g");
    cout << s;
    return 0;
}

