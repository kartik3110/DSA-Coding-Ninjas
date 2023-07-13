#include <iostream>
using namespace std;
int allIndexes(int *input, int size, int x, int *output)
{
    if (size == 0)
    {
        return 0;
    }
    int smallSize = allIndexes(input + 1, size - 1, x, output);
    for (int i = 0; i < smallSize; i++)
    {
        output[i]++;
    }
    if (input[0] == x)
    {
        for (int j = smallSize - 1; j >= 0; j--) // shifting
        {
            output[j + 1] = output[j];
        }
        output[0] = 0;
        return smallSize + 1;
    }
    return smallSize;
}
int main()
{
    // output all the indices of x in the array.
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