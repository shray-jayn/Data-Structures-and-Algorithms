#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int minSwaps(vector<int> &nums)
{
    int n = nums.size();

    vector<pair<int, int>> pairArr;

    for (int i = 0; i < n; i++)
    {
        pairArr.push_back({i, nums[i]});
    }

    sort(nums.begin(), nums.end());

    int ans = 0;

    vector<bool> isVis(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (isVis[i] == true or pairArr[i].second == i)
        {
            continue;
        }

        int cycleLen = 0;
        int j = i;

        while (isVis[j] == false)
        {
            isVis[j] = true;    
            cycleLen++;
            j = pairArr[j].second;
        }

        ans += cycleLen - 1;
    }

    return ans;
}

int main()
{

    return 0;
}