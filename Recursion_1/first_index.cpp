#include <iostream>
using namespace std;
int firstIndex(int *input, int size, int x)
{
    if (size == 0)
    {
        return -1;
    }
    if (input[0] == x)
    {
        return 0;
    }
    int ans = firstIndex(input + 1, size - 1, x);
    if (ans == -1)
    {
        return -1;
    }
    else
        return ans + 1;
}
int main()
{
    int x = 5;
    int size = 5;
    int arr[5] = {2, 9, 8, 9, 8};
    cout << firstIndex(arr, size, x);
    return 0;
}