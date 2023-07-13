#include <iostream>
#include <cstring>
using namespace std;
void replacePi(char *input)
{
    if (strlen(input) == 0)
    {
        return;
    }
    if (input[0] == 'p' && input[1] == 'i')
    {
        for (int i = strlen(input); i > 1; i--)
        {
            input[i + 2] = input[i];
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }
    replacePi(input + 1);
}
int main()
{
    char x[4] = "pix";
    replacePi(x);
    cout << x;
    return 0;
}