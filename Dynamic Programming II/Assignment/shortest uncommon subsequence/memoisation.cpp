#include <bits/stdc++.h>
using namespace std;

int memo[1000][1000]; // for every possible s index and v index, store the shortest unocommon subseq
// by refernce as passing by value takes time, and casuses TLE
int uncommonSubseq(string &s, string &v, int sIndex, int vIndex)
{
    // base case
    if (sIndex >= s.size())
    {
        return 1e9;
    }
    if (memo[sIndex][vIndex] != -1)
        return memo[sIndex][vIndex];
    // dont take s[i]
    int noTake = uncommonSubseq(s, v, sIndex + 1, vIndex);

    // if i assume s[0] is in the ans, lets say 'a', find the first occurence of 'a' in V and try to find the samllest sub seq in that
    int k;
    for (k = vIndex; k < v.size(); k++)
    {
        if (v[k] == s[sIndex])
            break;
    }
    if (k == v.size()) // 'a' was not found in v. it is an uncommon subsequence
    {
        return 1;
    }
    int take = 1 + uncommonSubseq(s, v, sIndex + 1, k + 1);
    memo[sIndex][vIndex] = min(take, noTake);
    return min(take, noTake);
}

int solve(string s, string v)
{
    memset(memo, -1, sizeof(memo));
    return uncommonSubseq(s, v, 0, 0);
}