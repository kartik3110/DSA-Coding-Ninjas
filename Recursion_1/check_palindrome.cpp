#include <iostream>
#include <cstring>
using namespace std;
bool checkPalindrome(char *input)
{
    if (strlen(input) == 0)
    {
        return true;
    }

    if (input[0] == input[strlen(input) - 1])
    {
        input[strlen(input) - 1] = '\0';
        return checkPalindrome(input + 1);
    }
    else
        return false;
}
int main()
{
    char name[10] = "racecar";
    cout << checkPalindrome(name);
    return 0;
}