#include <iostream>
using namespace std;
int sumOfDigits(int x)
{
    if (x == 0)
    {
        return 0;
    }
    return x % 10 + sumOfDigits(x / 10);
}
int main()
{
    int x = 1234;
    cout << sumOfDigits(x);
    return 0;
}