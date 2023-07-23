#include <iostream>
using namespace std;
#include <unordered_map>
string uniqueChar(string str)
{
    // Write your code here
    string ans = "";
    unordered_map<char, int> freq;
    for (int i = 0; i < str.length(); i++)
    {
        if (freq[str[i]] == 0) // univisited character
        {
            ans += str[i];
            freq[str[i]]++; // marked visited
        }
    }
    return ans;
}
// a set is better suited for such purposes where 'value' of the key is not required
