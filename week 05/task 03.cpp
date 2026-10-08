#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(string exp)
{
    stack<int> s;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        // If number, push into stack
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }

        // If operator
        else
        {
            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            int result;

            if (ch == '+')
            {
                result = a + b;
            }
            else if (ch == '-')
            {
                result = a - b;
            }
            else if (ch == '*')
            {
                result = a * b;
            }
            else if (ch == '/')
            {
                result = a / b;
            }
            else
            {
                result = 0;
            }

            s.push(result);
        }
    }

    return s.top();
}

int main()
{
    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    cout << "Result: "
         << evaluatePostfix(postfix);

    return 0;
}
