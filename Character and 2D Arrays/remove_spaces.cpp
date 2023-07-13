#include <iostream>
#include <cstring>
using namespace std;

void trimSpaces(char input[])
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
        {
            for (int j = i; input[j] != '\0'; j++)
            {
                input[j] = input[j + 1];
            }
            i--; // i should not increment if space was found as there might be two spaces
        }
    }
}

int main()
{
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}
