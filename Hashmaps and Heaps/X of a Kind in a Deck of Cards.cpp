#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int gcdCal(int a, int b)
{
    return __gcd(a, b);
}

bool hasGroupsSizeX(vector<int> &deck)
{
    int n = deck.size();

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[deck[i]]++;
    }

    int gcd = 0;

    for (auto it : mp)
    {
        int val = it.second;
        gcd = gcdCal(gcd, val);
    }

    if (gcd >= 2)
    {
        return true;
    }

    return false;
}

int main()
{

    return 0;
}