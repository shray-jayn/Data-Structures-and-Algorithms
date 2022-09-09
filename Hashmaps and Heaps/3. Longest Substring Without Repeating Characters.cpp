#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int lengthOfLongestSubstring(string s)
{
    int n = s.size();

    int ans = 0;
    int i = -1;
    int j = -1;

    unordered_map<char, int> mp;

    while (true)
    {
        bool flag1 = false;
        bool flag2 = false;

        // acquire

        while (i < n - 1)
        {
            i++;
            char ch = s[i];
            mp[ch]++;

            if (mp[ch] == 2)
            {
                break;
            }
            else
            {
                int len = i - j;

                ans = max(len, ans);
            }

            flag1 = true;
        }

        // release

        while (j < i)
        {
            j++;
            char ch = s[j];

            mp[ch]--;

            if (mp[ch] == 1) // made the frequency valid
            {
                break;
            }

            flag2 = true;
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