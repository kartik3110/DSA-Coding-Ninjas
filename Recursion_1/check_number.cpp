#include <iostream>
using namespace std;
bool checkNumber(int *input, int size, int x)
{
    if (size == 0)
    {
        return false;
    }
    if (input[size - 1] == x || checkNumber(input, size - 1, x))
    {
        return true;
    }
    return false;
}
int main()
{
    int x = 8;
    int input[5] = {2, 6, 5, 9, 1};
    cout << checkNumber(input, 5, x);
    return 0;
}