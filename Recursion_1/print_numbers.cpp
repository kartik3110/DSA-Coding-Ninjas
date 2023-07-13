#include <iostream>
using namespace std;
void print(int n)
{
    if (n == 1)
    {
        cout << 1 << " ";
        return;
    }
    print(n - 1);
    cout << n << " ";
    return;
}
int main()
{
    int n = 15;
    print(n);
    return 0;
}