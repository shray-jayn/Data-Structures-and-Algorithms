#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> findAnagrams(string s, string p)
{
    int n = s.size();
    int m = p.size();

    unordered_map<char, int> sourceMap;
    unordered_map<char, int> patternMap;

    for (int i = 0; i < m; i++)
    {
        char ch = p[i];
        patternMap[ch]++;
    }

    for (int i = 0; i < m; i++)
    {
        char ch = p[i];
        sourceMap[ch]++;
    }

    int j = 0;
    int i = m;
    int count = 0;

    vector<int> ans;

    while (i < n)
    {
        if (sourceMap == patternMap)
        {
            count++;
            ans.push_back(i - m); // push first index of each pattern
        }

        char ch = s[i];
        sourceMap[ch]++;

        char release = s[i - m];

        if (sourceMap[release] == 1)
        {
            sourceMap.erase(release);
        }
        else
        {
            sourceMap[release]--;
        }
    }

    if (sourceMap == patternMap)
    {
        count++;
    }
}

int main()
{

    return 0;
}