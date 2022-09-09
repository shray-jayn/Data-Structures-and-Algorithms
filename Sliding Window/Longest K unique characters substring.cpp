#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int longestKSubstr(string s, int k)
{
    int n = s.size();

    int i = 0, j = 0;

    unordered_map<char, int> mp;

    int maxlen = 0;

    while (j < n)
    {
        mp[s[j]]++;

        if (mp.size() < k)
        {
            j++;
        }
        else if (mp.size() == k)
        {
            maxlen = max(maxlen, j - i + 1);
            j++;
        }
        else if (mp.size() > k)
        {
            while (mp.size() > k)
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

    if (maxlen == 0)
    {
        return -1;
    }

    return maxlen;
}

int main()
{

    string s;
    cin >> s;

    int k;
    cin >> k;

    cout << longestKSubstr(s, k) << endl;

    return 0;
}