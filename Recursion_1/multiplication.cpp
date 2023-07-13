#include <iostream>
using namespace std;
int multiplyNumbers(int m, int n)
{
    if (n == 1)
    {
        return m;
    }
    return multiplyNumbers(m, n - 1) + m;
}
int main()
{
    int m = 4;
    int n = 9;
    cout << multiplyNumbers(m, n);
    return 0;
}