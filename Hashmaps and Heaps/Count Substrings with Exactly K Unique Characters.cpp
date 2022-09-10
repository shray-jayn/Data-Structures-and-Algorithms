#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int solutionForK1(string s)
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
            flag1 = true;

            i++;
            char ch = s[i];
            mp[ch]++;

            if (mp[ch] == 2)
            {
                removeInMap(mp, ch);
                i--;
                break;
            }
        }

        while (j < i)
        {
            flag2 = true;

            if (mp.size() == 1)
            {
                ans += i - j;
            }
            j++;

            char ch = s[i];
            removeInMap(mp, ch);

            if (mp.size() == 0)
            {
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

int substringsKUniqueChar(string s, int k)
{
    int n = s.size();

    if (k == 1)
    {
        return solutionForK1(s);
    }

    unordered_map<char, int> mpBig;
    unordered_map<char, int> mpSmall;

    int ans = 0;
    int is = -1, ib = -1;
    int j = -1;

    while (true)
    {
        bool flag1 = false;
        bool flag2 = false;
        bool flag3 = false;

        while (ib < n - 1)
        {
            flag1 = true;

            ib++;
            char ch = s[ib];
            mpBig[ch]++;

            if (mpBig.size() == k + 1)
            {
                removeInMap(mpBig, ch);
                ib--;
                break;
            }
        }

        while (is < ib)
        {
            flag2 = true;

            is++;
            char ch = s[is];
            mpSmall[ch]++;

            if (mpSmall.size() == k)
            {
                removeInMap(mpSmall, ch);
                is--;
                break;
            }
        }

        while (j < is)
        {
            flag3 = true;

            if (mpBig.size() == k and mpSmall.size() == k - 1)
            {
                ans += ib - is;
            }

            j++;
            char ch = s[j];

            removeInMap(mpSmall, ch);
            removeInMap(mpBig, ch);

            if (mpSmall.size() < k - 1 or mpBig.size() < k)
            {
                break;
            }
        }

        if (flag1 == false and flag2 == false and flag3 == false)
        {
            break;
        }
    }

    return ans;
}

void removeInMap(unordered_map<char, int> &mp, char ch)
{
    if (mp[ch] == 1)
    {
        mp.erase(ch);
    }
    else
    {
        mp[ch]--;
    }
}
