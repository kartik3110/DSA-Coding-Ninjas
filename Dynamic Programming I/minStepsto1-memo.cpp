#include <bits/stdc++.h>
using namespace std;

int countStepsToOneHelper(int n, int *minStepsArr)
{
    if (n <= 1)
        return 0;

    if (minStepsArr[n] != -1)
        return minStepsArr[n];

    int x = countStepsToOneHelper(n - 1, minStepsArr);
    int y = INT_MAX;
    int z = INT_MAX;
    if (n % 2 == 0)
        y = countStepsToOneHelper(n / 2, minStepsArr);
    if (n % 3 == 0)
        z = countStepsToOneHelper(n / 3, minStepsArr);

    int ans = min(x, min(y, z)) + 1;
    minStepsArr[n] = ans;
    return ans;
}
int countStepsToOne(int n)
{
    int *minStepsArr = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        minStepsArr[i] = -1;
    }
    return countStepsToOneHelper(n, minStepsArr);
}