#include <iostream>
using namespace std;
// gloabal array for keypad codes
string codes[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int keypad(int input, string *output)
{
    if (input == 0 || input == 1)
    {
        output[0] = "";
        return 1;
    }

    int smallSize = keypad(input / 10, output);
    int jSize = codes[input % 10].size();
    int biggerSize = jSize * smallSize;
    string temp[biggerSize];
    int j = 0, count = 0;
    for (int i = 0; i < smallSize; i++)
    {
        j = 0;
        while (j < jSize)
        {
            temp[count] = output[i] + codes[input % 10][j];
            count++;
            j++;
        }
    }

    for (int k = 0; k < biggerSize; k++)
    {
        output[k] = temp[k];
    }
    return biggerSize;
}
int main()
{
    int number = 23;
    string *outputArray = new string[1000];
    int size = keypad(number, outputArray);
    for (int i = 0; i < size; i++)
    {
        cout << outputArray[i] << endl;
    }
    return 0;
}