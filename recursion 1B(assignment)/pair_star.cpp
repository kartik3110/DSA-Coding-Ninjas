#include <iostream>
#include <cstring>
using namespace std;
void pairStar(char *input)
{
    if (strlen(input) == 0)
    {
        return;
    }
    pairStar(input + 1);
    if (input[0] == input[1])
    {
        for (int i = strlen(input); i > 0; i--)
        {
            input[i + 1] = input[i];
        }
        input[1] = '*';
    }
}
int main()
{
    char input[5] = "abbc";
    pairStar(input);
    cout << input;
    return 0;
}