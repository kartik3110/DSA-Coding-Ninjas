#include <iostream>
using namespace std;
int lastIndex(int *input, int size, int x)
{
    if (size == 0)
    {
        return -1;
    }
    if (input[size - 1] == x)
    {
        return size - 1;
    }
    int ans = lastIndex(input, size - 1, x);
    if (ans == -1)
    {
        return -1;
    }
    return ans;
}
int main()
{
    int x = 7;
    int size = 5;
    int arr[5] = {4, 7, 6, 7, 78};
    cout << lastIndex(arr, size, x);
    return 0;
}