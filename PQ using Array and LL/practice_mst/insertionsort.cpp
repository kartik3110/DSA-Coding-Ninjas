#include <iostream>
using namespace std;
void insertionSort(int *input, int size)
{
    int i = 1;
    int temp;
    while (i < size)
    {
        temp = input[i];
        // scan left and insert ith element to its correct position to its left .
        int j = i - 1;
        while (j >= 0)
        {
            if (input[j] > temp)
                input[j + 1] = input[j];
            else
                break;
            j--;
        }
        input[j + 1] = temp;
        i++;
    }
}
int main()
{

    return 0;
}