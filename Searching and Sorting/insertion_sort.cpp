#include <iostream>
using namespace std;

void insertionSort(int input[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        int temp = input[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (input[j] > temp)
            {
                input[j + 1] = input[j];
            }
            else
                break;
        }
        input[j + 1] = temp; // j will be -1 when the loop stops!(not in every case of course)
    }
    cout << "j= " << j << endl;
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

        insertionSort(input, size);

        for (int i = 0; i < size; i++)
        {
            cout << input[i] << " ";
        }

        delete[] input;
        cout << endl;
    }

    return 0;
}