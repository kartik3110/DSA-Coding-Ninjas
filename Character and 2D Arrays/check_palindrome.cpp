#include <iostream>
#include <cstring>
using namespace std;

int length(char str[])
{
    int count;
    for (int x = 0; str[x] != '\0'; x++)
    {
        count++;
    }
    return count;
}
bool checkPalindrome(char str[])
{
    int j = (length(str) - 1);
    int i = 0;
    while (i <= j)
    {
        if (str[i++] != str[j--])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << (checkPalindrome(str) ? "true" : "false");
}