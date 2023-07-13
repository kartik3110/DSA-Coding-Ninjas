#include <iostream>
using namespace std;
int allIndexes(int *input, int size, int x, int *output)
{
    if (size == 0)
    {
        return 0;
    }
    int smallSize = allIndexes(input, size - 1, x, output);
    if (input[size - 1] == x)
    {
        output[smallSize] = size - 1;
        return smallSize + 1;
    }
    else
        return smallSize;
}

int main()
{
    int x = 7;
    int input[5] = {5, 2, 7, 9, 7};
    int size = 5;
    int output[5];
    int finalSize = allIndexes(input, size, x, output);
    for (int i = 0; i < finalSize; i++)
    {
        cout << output[i] << " ";
    }
    return 0;
}