#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int priority(char op)
{
    if (op == '^')
        return 3;

    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

string infixToPostfix(string exp)
{
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        // Operand
        if (isalnum(ch))
        {
            postfix = postfix + ch;
        }

        // Opening bracket
        else if (ch == '(')
        {
            s.push(ch);
        }

        // Closing bracket
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix = postfix + s.top();
                s.pop();
            }

            if (!s.empty())
            {
                s.pop();
            }
        }

        // Operator
        else
        {
            while (!s.empty() &&
                   s.top() != '(' &&
                   priority(s.top()) >= priority(ch))
            {
                postfix = postfix + s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.empty())
    {
        postfix = postfix + s.top();
        s.pop();
    }

    return postfix;
}

int main()
{
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: "
         << infixToPostfix(infix);

    return 0;
}
