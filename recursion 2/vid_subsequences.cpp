#include <iostream>
using namespace std;
int subsequences(string input, string *output)
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }
    int smallSize = subsequences(input.substr(1), output);
    for (int i = 0; i < smallSize; i++)
    {
        output[smallSize + i] = input[0] + output[i]; // concatenation
    }
    return 2 * smallSize;
}
int main()
{
    string name = "kartikgu";
    string *outputArray = new string[1000];
    int size = subsequences(name, outputArray);
    for (int i = 0; i < size; i++)
    {
        cout << outputArray[i] << endl;
    }
    return 0;
}