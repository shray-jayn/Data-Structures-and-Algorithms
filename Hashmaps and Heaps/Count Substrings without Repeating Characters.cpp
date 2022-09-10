#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int countWithoutRepeating(string s)
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

            if (mp[ch] == 2)
            {
                break;
            }

            else
            {
                ans += i - j;
            }

            flag1 = true;
        }

        while (j < i)
        {
            j++;
            char ch = s[j];

            mp[ch]--;

            if (mp[ch] == 1)
            {
                ans += i - j;
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