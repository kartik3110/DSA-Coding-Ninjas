#include <iostream>
#include <climits>
using namespace std;

int findSecondLargest(int *input, int size)
{
    if (size <= 0)
    {
        return INT_MIN;
    }
    int max = input[0];
    int secondMax = INT_MIN;
    for (int i = 1; i < size; i++)
    {
        if (input[i] > max)
        {
            secondMax = max;
            max = input[i];
        }
        else if (input[i] > secondMax && input[i] < max)
        {
            secondMax = input[i];
        }
    }
    return secondMax;
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

        cout << findSecondLargest(input, size) << endl;

        delete[] input;
    }

    return 0;
}