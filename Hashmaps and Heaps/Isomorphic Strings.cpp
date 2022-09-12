#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isIsomorphic(string s, string t)
{
    int n = s.size();
    int m = t.size();

    if (n != m)
    {
        return false;
    }

    unordered_map<char, char> mp1;
    unordered_map<char, bool> mp2;

    for (int i = 0; i < n; i++)
    {
        char ch1 = s[i];
        char ch2 = t[i];

        if (mp1.find(ch1) != mp1.end())
        {
            if (mp1[ch1] != ch2)
            {
                return false;
            }
        }

        else
        {
            if (mp2.find(ch2) != mp2.end() and mp2[ch2] == true)
            {
                return false;
            }
            else
            {
                mp1[ch1] = ch2;
                mp2[ch2] = true;
            }
        }
    }

    return true;
}

int main()
{

    return 0;
}