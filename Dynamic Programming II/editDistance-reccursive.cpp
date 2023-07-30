#include <bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2)
{
    // Write your code here
    if (s1.size() == 0 || s2.size() == 0)
        return 0;
    if (s1[0] == s2[0])
        return editDistance(s1.substr(1), s2.substr(1));

    // add
    int a = editDistance(s1.substr(1), s2) + 1;
    // update
    int b = editDistance(s1.substr(1), s2.substr(1)) + 1;
    // delete
    int c = editDistance(s1.substr(1), s2.substr(1)) + 1;
    return min(a, min(b, c));
}

int main()
{
    string s = "good";
    string t = "goodbye";
    cout << editDistance(s, t);
}