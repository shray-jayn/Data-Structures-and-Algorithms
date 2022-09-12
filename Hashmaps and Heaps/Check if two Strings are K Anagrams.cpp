#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool areKAnagramns(string s1, string s2, int k)
{
    int n1 = s1.size();
    int n2 = s2.size();

    if (n1 != n2)
    {
        return false;
    }

    unordered_map<char, int> mp;

    for (int i = 0; i < n1; i++)
    {
        char ch = s1[i];
        mp[ch]++;
    }

    for (int i = 0; i < n2; i++)
    {
        char ch = s2[i];

        if (mp.find(ch) != mp.end())
        {
            mp[ch]--;
        }
        else
        {
            mp[ch] = 0;
        }
    }

    int count = 0;

    for (auto it : mp)
    {
        count += it.second;
    }

    if (count > k)
    {
        return false;
    }

    return true;
}

int main()
{

    return 0;
}