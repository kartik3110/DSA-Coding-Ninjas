#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

// code works fine in online compiler, vscode handles pow a little differently.
int stringToNumber(char *input)
{
    int n = strlen(input);
    if (n == 1)
    {
        return input[0] - 48;
    }
    int a = stringToNumber(input + 1);
    int b = (input[0] - 48) * pow(10, n - 1);
    a = b + a;
    return a;
}
int main()
{
    char input[5] = "1234";
    cout << stringToNumber(input);
    return 0;
}