#include <iostream>
#include <cstring>
using namespace std;
void replaceCharacter(char *input, char c1, char c2)
{
    if (strlen(input) == 0)
    {
        return;
    }
    if (input[0] == c1)
    {
        input[0] = c2;
    }
    replaceCharacter(input + 1, c1, c2);
}
int main()
{
    char name[10] = "kartik";
    replaceCharacter(name, 'k', 'g');
    cout << name;
    return 0;
}