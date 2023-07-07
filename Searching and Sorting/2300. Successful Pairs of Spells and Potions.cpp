#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int binarySearch(int start, int end, int key, vector<int> &potions)
{
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (potions[mid] >= key)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (potions[mid] < key)
        {
            start = mid + 1;
        }
    }

    return ans;
}

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    int n = spells.size();
    int m = potions.size();

    sort(potions.begin(), potions.end());

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        int key = (success + spells[i] - 1) / spells[i];
        int idx = binarySearch(0, m - 1, key, potions);

        if (idx == -1)
        {
            ans[i] = 0;
        }
        else
        {
            ans[i] = m - idx;
        }
    }

    return ans;
}

int main()
{
    vector<int> spells = {3, 1, 2};
    vector<int> potions = {8, 5, 8};
    long long success = 16;

    vector<int> ans = successfulPairs(spells, potions, success);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}