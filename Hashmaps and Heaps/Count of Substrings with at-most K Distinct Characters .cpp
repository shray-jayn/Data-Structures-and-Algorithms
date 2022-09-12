#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int countOfAtmostKUnique(string s, int k)
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

            if (mp.size() <= k)
            {
                ans += i - j;
            }
            else
            {
                break;
            }
        }

        if (i == n - 1 and mp.size() <= k)
        {
            break;
        }

        while (j < i)
        {

            j++;
            char ch = s[j];

            if (mp[ch] == 1)
            {
                mp.erase(ch);
            }
            else
            {
                mp[ch]--;
            }
            if (mp.size() <= k)
            {
                ans += i - j;
                break;
            }
            else
            {
                continue;
            }
        }
    }

    return ans;
}
int main()
{

    return 0;
}