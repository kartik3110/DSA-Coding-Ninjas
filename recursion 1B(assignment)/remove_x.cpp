#include <iostream>
#include <cstring>
using namespace std;
void removeX(char *input)
{
    if (strlen(input) <= 0)
    {
        return;
    }
    removeX(input + 1);
    // we cant put recursive call later as it will fail for double xx in the string(eg. pxxp)
    // if we want, we will have to do a removeX(input) in the if statement and removeX(input +1) in else.
    if (input[0] == 'x')
    {
        for (int i = 0; i < strlen(input); i++)
        {
            input[i] = input[i + 1];
        }
    }
}
int main()
{
    char input[30];
    cin >> input;
    removeX(input);
    cout << input;
    return 0;
}