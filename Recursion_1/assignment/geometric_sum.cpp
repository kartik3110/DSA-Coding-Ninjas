#include <iostream>
#include <cmath>
using namespace std;
double geometricSum(int k)
{
    if (k == 0)
    {
        return 1;
    }
    return (1.0 / (1 << k)) + geometricSum(k - 1); // x<<y = x.(2^y)
}
int main()
{
    int k = 6;
    cout << geometricSum(k);
    return 0;
}