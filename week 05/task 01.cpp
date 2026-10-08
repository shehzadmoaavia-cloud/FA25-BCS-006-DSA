#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string exp)
{
    stack<char> s;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        // Opening brackets
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }

        // Closing brackets
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.empty())
            {
                return false;
            }

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                return false;
            }
        }
    }

    return s.empty();
}

int main()
{
    string exp;

    cout << "Enter brackets: ";
    cin >> exp;

    if (isBalanced(exp))
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not Balanced";
    }

    return 0;
}
