#include <iostream>
using namespace std;
// populating first column of 2d array with the size of corresponding rows.
int mySubset(int *input, int size, int output[][20], int si)
{
    if (si == size)
    {
        output[0][0] = 0;
        return 1;
    }
    int smallSize = mySubset(input, size, output, si + 1);
    for (int i = 0; i < smallSize; i++)
    {
        output[i + smallSize][0] = output[i][0] + 1; // populate first column with sizes
        output[i + smallSize][1] = input[si];        // appending with start index

        for (int j = 1; j <= output[i][0]; j++)
        {
            output[i + smallSize][j + 1] = output[i][j];
        }
    }
    return 2 * smallSize;
}
int subset(int *input, int size, int output[][20])
{
    return mySubset(input, size, output, 0);
}

int main()
{
    int input[20], length, output[35000][20];
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    int size = subset(input, length, output);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
