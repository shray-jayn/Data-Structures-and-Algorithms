#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node
{
    Node *links[2];

    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }

    Node *get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

public:
    void insert(int num)
    {
        Node *node = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1); // checks if ith bit is set or not

            if (!node->containsKey(bit))
            {
                node->put(bit, node);
            }

            node = node->get(bit);
        }
    }

public:
    int getMax(int num)
    {
        Node *node = root;

        int maxNum = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1); // checks if ith bit is set or not

            if (node->containsKey(1 - bit)) // if it contains opp. bit
            {
                maxNum = maxNum | (1 << i); // get the max

                node = node->get(1 - bit);
            }

            else
            {
                node = node->get(bit); // just go to next node
            }
        }

        return maxNum;
    }
};

vector<int> maximizeXor(vector<int> &arr, vector<vector<int>> &queries)
{

    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<pair<int, pair<int, int>>> offlineQueries;

    int q = queries.size();

    for (int i = 0; i < q; i++)
    {
        offlineQueries.push_back({queries[i][1], {queries[i][0], i}}); // <ai,xi, i>
    }

    sort(offlineQueries.begin(), offlineQueries.end());

    vector<int> ans(q, 0);

    int idx = 0;

    Trie trie;

    for (int i = 0; i < q; i++)
    {
        int ai = offlineQueries[i].first;
        int xi = offlineQueries[i].second.first;
        int querieIdx = offlineQueries[i].second.second;

        while (idx < n and arr[idx] <= arr[i])
        {
            trie.insert(arr[idx]);
            idx++;
        }

        if (idx == 0)
        {
            ans[querieIdx] = -1;
        }
        else
        {
            ans[querieIdx] = trie.getMax(xi);
        }
    }

    return ans;
}
