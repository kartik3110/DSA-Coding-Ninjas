#include <iostream>
using namespace std;
void towerOfHanoi(int n, char source, char aux, char destination)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, source, destination, aux);
    cout << source << " " << destination << endl;
    towerOfHanoi(n - 1, aux, source, destination);
}
int main()
{
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
    return 0;
}