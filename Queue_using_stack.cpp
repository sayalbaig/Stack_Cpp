#include <iostream>
using namespace std;

class Stack
{
    int *data;
    int size;
    int top;

public:
    Stack()
    {
        top = 0;
        size = 0;
        data = NULL;
    }

    Stack(int size)
    {
        this->size = size;
        top = 0;
        this->data = new int[this->size];
    }

    void push(int data)
    {
        if (top < size)
        {
            this->data[top] = data;
            top++;
        }
        else
        {
            cout << "Stack overflow: No more space left.\n";
        }
    }

    int pop()
    {
        if (top == 0)
        {
            cout << "Stack underflow: Empty stack.\n";
            return -1;
        }
        int x = _top();
        top--;
        return x;
    }

    int _top()
    {
        if (top == 0)
        {
            cout << "Empty stack.\n";
            return -1;
        }
        return this->data[top - 1];
    }
    bool isEmpty()
    {
        if (top == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class Queue
{
    Stack s1, s2;

public:
    Queue()
    {
    }
    Queue(int size) : s1(size), s2(size)
    {
    }
    void push(int x)
    {

        while (!s1.isEmpty())
        {
            s2.push(s1.pop());
        }
        s1.push(x);
        while (!s2.isEmpty())
        {
            s1.push(s2.pop());
        }
    }
    int pop()
    {
        return s1.pop();
    }
};
bool isBalanced(Stack st, string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if(s[i]==')'|| s[i] == '}' || s[i] == ']')
        {
            if (st.isEmpty())
            {
                return false;
            }
            char tmp = st._top();
            st.pop();
            if (tmp == '(' && s[i] == ')' || tmp == '[' && s[i] == ']' || tmp == '{' && s[i] == '}')
            {
            }
            else
            {
                return false;
            }
        }
    }
    if (st.isEmpty())
    {
        return true;
    }
    return false;
}
int main()
{

    string s = {"{25 + (3 – 6) * 8}"};
    Stack temp(s.length());
    cout << isBalanced(temp, s);
    return 0;
}

