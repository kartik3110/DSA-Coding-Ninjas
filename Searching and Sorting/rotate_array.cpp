#include <iostream>
using namespace std;

void rotate(int *input, int d, int size)
{
    int i, j, k;
    int temp[d];
    for (i = 0; i < d; i++)
    {
        temp[i] = input[i];
    }
    for (j = 0; j < size - d; j++)
    {
        input[j] = input[j + d];
    }
    for (k = size - d; k < size; k++)
    {
        input[k] = temp[k + -size + d];
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        cin >> size;

        int *input = new int[size];

        for (int i = 0; i < size; ++i)
        {
            cin >> input[i];
        }

        int d;
        cin >> d;

        rotate(input, d, size);

        for (int i = 0; i < size; ++i)
        {
            cout << input[i] << " ";
        }

        delete[] input;
        cout << endl;
    }

    return 0;
}