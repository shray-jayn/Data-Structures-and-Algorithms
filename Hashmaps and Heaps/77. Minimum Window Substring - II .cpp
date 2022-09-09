#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int minWindow(string s)
{
    int n = s.size();

    unordered_set<char> unique;

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        unique.insert(s[i]);
    }

    int len = n; // all string can be an ans
    int i = -1;
    int j = -1;

    unordered_map<char, int> mp;

    while (true)
    {
        bool flag1 = false;
        bool flag2 = false;

        // acquire till map.size() < set.size()

        while (i < n - 1 and mp.size() < unique.size())
        {
            i++;
            char ch = s[i];
            mp[ch]++;

            flag1 = true;
        }

        // collect ans and release

        while (j < i and mp.size() == unique.size())
        {
            int potentialAns = i - j;

            len = min(len, potentialAns);

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

            flag2 = true;
        }

        if (flag1 == false and flag2 == false)
        {
            break;
        }
    }

    return len;
}

int main()
{

    return 0;
}