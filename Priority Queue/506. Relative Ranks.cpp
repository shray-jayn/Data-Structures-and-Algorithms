#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<string> findRelativeRanks(vector<int> &score)
{
    int n = score.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push({score[i], i + 1});
    }

    vector<pair<int, string>> res;

    int k = n;

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        int idx = curr.second;
        string val;

        if (pq.size() > 3)
        {
            val = to_string(k);
            k--;
            res.push_back({idx, val});
        }
        else
        {
            if (pq.size() == 2)
            {
                val = "Bronze Medal";
            }
            else if (pq.size() == 1)
            {
                val = "Silver Medal";
            }
            else if (pq.size() == 0)
            {
                val = "Gold Medal";
            }

            res.push_back({idx, val});
        }
    }

    sort(res.begin(), res.end());

    vector<string> ans;

    for (int i = 0; i < n; i++)
    {
        ans.push_back(res[i].second);
    }

    return ans;
}

int main()
{

    return 0;
}