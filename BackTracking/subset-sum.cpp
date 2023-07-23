#include <bits/stdc++.h>
using namespace std;
int ans = 0, size;
void subsetCount(int *arr, int k, int sum, int currIndex)
{
    if (currIndex == size)
    {
        if (sum == k)
            ans++;
        return;
    }
    // 2 choices: either take current element in the sum or skip.
    subsetCount(arr, k, sum + arr[currIndex], currIndex + 1);
    subsetCount(arr, k, sum, currIndex + 1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> size >> k;
        int *arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        subsetCount(arr, k, 0, 0);
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}

// OTHER APPROACH

// #include <bits/stdc++.h>
// using namespace std;
// int subsetCount(int *arr, int k, int sum, int currIndex, int size)
// {
//     if (currIndex == size)
//     {
//         if (sum == k)
//             return 1;
//         return 0;
//     }
//     //2 choices: either take current element in the sum or skip.
//     int ans1 =  subsetCount(arr, k, sum + arr[currIndex], currIndex + 1, size);
//     int ans2 =  subsetCount(arr, k, sum, currIndex + 1, size);
//     return ans1 + ans2;
// }
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int k, size;
//         cin >> size >> k;
//         int *arr = new int[size];
//         for (int i = 0; i < size; i++)
//         {
//             cin >> arr[i];
//         }

//         cout << subsetCount(arr, k, 0, 0, size) << endl;
//     }
//     return 0;
// }