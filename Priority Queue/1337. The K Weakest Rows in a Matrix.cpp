#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Compare
{
public:
    bool operator()(pair<int, int> below, pair<int, int> above)
    {
        if (below.first > above.first)
        {
            return true;
        }

        else if (below.first == above.first && below.second < above.second)
        {
            return true;
        }

        return false;
    }
};

int binarySearch(vector<int> arr, int n)
{
    int start = 0;
    int end = n - 1;

    int key = 0;
    int idx = 0;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            idx = mid;
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }

    return idx;
}

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    int n = mat.size();
    int m = mat[0].size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    for (int i = 0; i < n; i++)
    {
        int count = binarySearch(mat[i], m);

        pq.push({count, i});

        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    vector<int> ans;

    while (pq.size())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}