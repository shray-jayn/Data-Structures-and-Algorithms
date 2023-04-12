#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int takeCharacters(string s, int k)
{

    int n = s.size();
    unordered_map<char, int> mp;
    mp['a'] = 0;
    mp['b'] = 0;
    mp['c'] = 0;

    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }

    for (auto it : mp)
    {
        if (it.second < k)
        {
            return -1;
        }
    }

    int i = 0;
    int j = -1;

    int count_a = 0;
    int count_b = 0;
    int count_c = 0;

    int ka = mp['a'] - k;
    int kb = mp['b'] - k;
    int kc = mp['c'] - k;

    int len = 0;

    while (i < n)
    {
        // aquire karo

        if (s[i] == 'a')
        {
            count_a++;
            i++;
        }
        else if (s[i] == 'b')
        {
            count_b++;
            i++;
        }
        else if (s[i] == 'c')
        {
            count_c++;
            i++;
        }

        if (count_a <= ka and count_b <= kb and count_c <= kc)
        {
            int sze = i - j;
            len = max(len, sze);
        }

        while (count_a > ka or count_b > kb or count_c > kc)
        {
            j++;

            if (s[j] == 'a')
            {
                count_a--;
            }
            else if (s[j] == 'b')
            {
                count_b--;
            }
            else if (s[j] == 'c')
            {
                count_c--;
            }
        }
    }

    if (count_a <= ka and count_b <= kb and count_c <= kc)
    {
        int sze = i - j;
        len = max(len, sze);
    }

    return n - len + 1;
}

int main()
{

    return 0;
}