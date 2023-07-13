#include <iostream>
using namespace std;
int countZeros(int x)
{

    if (x == 0) // just handling when user inputs 0
    {
        return 1;
    }
    else if (x < 10)
    {
        return 0;
    }
    if (x % 10 == 0)
    {
        return countZeros(x / 10) + 1;
    }
    else
        return countZeros(x / 10);
}
int main()
{
    int x = 2003;
    cout << countZeros(x);
    return 0;
}