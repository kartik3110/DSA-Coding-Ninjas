#include <iostream>
#include <cstring>
using namespace std;

void printSubstrings(char str[])
{
    for (int start = 0; str[start] != '\0'; start++)
    {
        for (int i = start; str[i] != '\0'; i++)
        {
            for (int j = i; j <= i; j++)
            {
                cout << str[j];
            }
            cout << endl;
        }
    }
}

int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    printSubstrings(str);
}