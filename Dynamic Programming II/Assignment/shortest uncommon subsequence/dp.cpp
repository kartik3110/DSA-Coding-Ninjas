#include <bits/stdc++.h>
using namespace std;




int dp[1000][1000]; // for every possible s index and v index, store the shortest unocommon subseq
int uncommonSubseq(string &s, string &v, int sIndex, int vIndex)
{
    // base case
    if (sIndex >= s.size())
    {
        return 1e9;
    }
    if (dp[sIndex][vIndex] != -1)
        return dp[sIndex][vIndex];
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
    dp[sIndex][vIndex] = min(take, noTake);
    return min(take, noTake);
}

int solve(string s, string v)
{
    for (int sIndex = s.size() - 1; sIndex >= 0; sIndex--)
    {
        for (int vIndex = v.size() - 1; vIndex >= 0; vIndex--)
        {
            if (sIndex == s.size() - 1 || vIndex == v.size() - 1)
                dp[sIndex][vIndex] = 1001;
        }
    }
    
    for (int sIndex = 1; sIndex < s.size(); sIndex++)
    {
        for (int vIndex = 1; vIndex < v.size(); vIndex++)
        {
            
        }   
        
    }
    

    return dp[0][0];
}