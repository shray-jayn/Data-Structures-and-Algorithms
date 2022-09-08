#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    int n = arr.size();
    int m = queries.size();

    vector<int> prefixXOR(n, 0);

    prefixXOR[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefixXOR[i] = (prefixXOR[i - 1] ^ arr[i]);
    }

    vector<int> ans(m, 0);

    for (int i = 0; i < m; i++)
    {
        int left = queries[i][0];
        int right = queries[i][1];

        if (left == 0)
        {
            ans[i] = prefixXOR[right];
        }

        else
        {
            ans[i] = (prefixXOR[right] ^ prefixXOR[left - 1]);
        }
    }

    return ans;
}
