#include <iostream>
using namespace std;
int main()
{
    int arr[6] = {3, 4, 5, 6, 1, 2};
    int arr2[6] = {3, 4, 5, 6, 1, 2};
    int firstIndex = 4;
    int capacity = 6;
    int i = (firstIndex + 1) % capacity;
    int j = 0;
    while (i != firstIndex)
    {
        arr[j] = arr[i];
        j++;
        i = (i + 1) % capacity;
    }

    for (int k = 0; k < 6; k++)
    {
        cout << arr2[k] << " ";
    }

    return 0;
}