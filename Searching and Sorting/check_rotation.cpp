#include <iostream>
using namespace std;

int arrayRotateCheck(int *input, int size)
{
    int min = input[0];
    int minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (input[i] < min)
        {
            min = input[i];
            minIndex = i;
        }
    }
    return minIndex;
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

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cout << arrayRotateCheck(input, size) << endl;
        delete[] input;
    }

    return 0;
}