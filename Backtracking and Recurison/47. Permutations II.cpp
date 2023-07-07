#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int>> result;

void helper(int n, int currSize, vector<int> &ans, unordered_map<int, int> &mp)
{
    if (currSize == n)
    {
        result.push_back(ans);
        return;
    }

    for (auto it : mp)
    {
        if (it.second > 0)
        {
            mp[it.first]--;
            ans.push_back(it.first);

            helper(n, currSize + 1, ans, mp);

            mp[it.first]++;
            ans.pop_back();
        }
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    int n = nums.size();

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[nums[i]]++;
    }

    vector<int> ans;

    helper(n, 0, ans, freq);

    return result;
}

int main()
{

    return 0;
}