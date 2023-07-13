// (i still dont understand this code):\
#include <iostream>
using namespace std;
int myPrintSubsets(int *input, int size, int *output, int outputSize)
{
    if (size == 0)
    {
        // print what is in output
        for (int i = 0; i < outputSize; i++)
        {
            cout << output[i];
        }
        cout << endl;
        return 1;
    }
    myPrintSubsets(input + 1, size - 1, output, outputSize);
    int newOutput[outputSize + 1];
    for (int i = 0; i < outputSize; i++)
    {
        newOutput[i] = output[i];
    }
    newOutput[outputSize] = input[0];

    myPrintSubsets(input + 1, size - 1, newOutput, outputSize + 1);
}
void printSubsetsOfArray(int *input, int size)
{
    int outputSize = 0;
    int output[0];
    myPrintSubsets(input, size, output, outputSize);
}
int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
}