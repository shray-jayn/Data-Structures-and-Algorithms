#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int longestSubstringWithKDistinct(string s, int k)
{
    int n = s.size();

    unordered_map<char, int> mp;

    int ans = 0;
    int i = -1;
    int j = -1;

    while (true)
    {
        bool flag1 = false;
        bool flag2 = false;

        while (i < n - 1)
        {
            i++;
            char ch = s[i];
            mp[ch]++;

            if (mp.size() < k)
            {
                continue;
            }

            else if (mp.size() == k)
            {
                int len = i - j;
                ans = max(len, ans);
            }

            else if (mp.size() > k)
            {
                break;
            }
        }

        while (j < i)
        {
            j++;
            char ch = s[i];

            if (mp[ch] == 1)
            {
                mp.erase(ch);
            }
            else
            {
                mp[ch]--;
            }

            if (mp.size() > k)
            {
                continue;
            }
            else if (mp.size() == k)
            {
                int len = i - j;
                ans = max(len, ans);
                break;
            }
        }

        if (flag1 == false and flag2 == false)
        {
            break;
        }
    }

    return ans;
}

int main()
{

    return 0;
}