#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int lengthOfLongestSubstring(string s)
{

    int n = s.size();

    int i = 0, j = 0;

    int maxLen = 0;

    unordered_map<char, int> mp;

    while (j < n)
    {
        mp[s[j]]++;

        if (mp.size() == j - i + 1)
        {
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        else if (mp.size() < j - i + 1)
        {
            while (mp.size() < j - i + 1)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }

            j++;
        }
    }

    return maxLen;
}

int main()
{

    return 0;
}