#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<string> topKFrequent(vector<string> &words, int k)
{
    unordered_map<string, int> m;

    for (auto i : words)
        m[i]++;

    priority_queue<pair<int, string>> p; // max heap

    for (auto c : m)
    {
        p.push({-c.second, c.first}); // store in reverse way
        if (p.size() > k)
            p.pop();
    }

    vector<string> ans;

    while (k--)
    {
        ans.push_back(p.top().second);
        p.pop();
    }

    reverse(ans.begin(), ans.end()); // to get lexicographical order.

    return ans;
}

int main()
{

    return 0;
}