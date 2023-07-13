#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
bool isBalanced(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(')
        {
            s.push(expression[i]);
        }
        else if (expression[i] == ')' && !s.empty())
        {
            s.pop();
        }
        else if (expression[i] == ')' && s.empty())
        {
            return false;
        }
    }
    if (s.empty())
        return true;
    else
        return false;
}
int main()
{
    stack<char> container;
    string expression = "{22+(3*)6)-2}";
    cout << isBalanced(expression);

    return 0;
}