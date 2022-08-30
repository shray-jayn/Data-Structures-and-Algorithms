#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> partitionLabels(string s)
{
    int n = s.size();

    // Construct an unordered map

    unordered_map<char, int> mp;

    for (int i = 0; i < 26; i++)
    {
        mp['a' + i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        mp[s[i]] = i;
    }

    int maxIdx = 0;

    vector<int> partition;

    int prevIdx = 0;

    for (int i = 0; i < n; i++)
    {
        maxIdx = max(maxIdx, mp[s[i]]);

        if (maxIdx == i)
        {
            partition.push_back(i + 1 - prevIdx);
            prevIdx = i + 1;
        }
    }

    return partition;
}

int main()
{
    string s = "ababcbacadefegdehijhklij";

    vector<int> res = partitionLabels(s);

    for (auto s : res)
    {
        cout << s << " ";
    }
}
