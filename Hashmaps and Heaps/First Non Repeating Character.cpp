#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int solution(string s)
{
    int n = s.size();
    unordered_map<int, int> fmap;

    for (int i = 0; i < n; i++)
    {
        fmap[s[i]]++;
    }

    for (auto it : fmap)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }

    return -1;
}

int main()
{

    return 0;
}