#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool areKAnagrams(string str1, string str2, int k)
{
    int n1 = str1.size();
    int n2 = str2.size();

    if (n1 != n2)
    {
        return false;
    }

    unordered_map<char, int> mp;

    for (int i = 0; i < n1; i++)
    {
        mp[str1[i]]++;
    }

    for (int i = 0; i < n2; i++)
    {
        char ch = str2[i];

        if (mp.find(ch) != mp.end())
        {
            mp[ch]--;
        }
    }

    int count = 0;

    for (auto it : mp)
    {
        if (it.second != 0)
        {
            count++;
        }
    }

    if (count <= k)
    {
        return true;
    }

    return false;
}

int main()
{

    return 0;
}