#include <iostream>
#include <cstring>
using namespace std;
void removeConsecutiveDuplicates(char *input)
{
    if (strlen(input) == 0) // can also do without cstring by using input[0] == '\0'
    {
        return;
    }

    if (input[0] == input[1])
    {
        for (int i = 0; i < strlen(input); i++)
        {
            input[i] = input[i + 1];
        }
        removeConsecutiveDuplicates(input);
    }
    removeConsecutiveDuplicates(input + 1);
}
int main()
{
    char name[10] = "aabcdde";
    removeConsecutiveDuplicates(name);
    cout << name;
    return 0;
}