#include <iostream>
using namespace std;
int staircase(int n, int output = 0)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    return staircase(n - 1) + staircase(n - 2) + staircase(n - 3);
}
int main()
{
    int n = 5; // number of stairs
    cout << staircase(n);
    return 0;
}