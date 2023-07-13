#include <iostream>
using namespace std;
int sum(int *arr, int size)
{
    if (size == 2)
    {
        return arr[0] + arr[1];
    }
    return (sum(arr, size - 1) + arr[size - 1]); // sum of shorter array + current element
}
int main()
{
    int n = 6;
    int arr[6] = {1, 2, 3, 4, 5, 6};
    cout << sum(arr, n);
    return 0;
}