#include <iostream>
using namespace std;
string codes[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void printKeypad(int input, string output = "")
{
    if (input == 0)
    {
        cout << output << endl;
        return;
    }
    int jSize = codes[input % 10].size();
    for (int j = 0; j < jSize; j++)
    {
        printKeypad(input / 10, codes[input % 10][j] + output);
    }
}
int main()
{
    int num = 23;
    printKeypad(num);
    return 0;
}