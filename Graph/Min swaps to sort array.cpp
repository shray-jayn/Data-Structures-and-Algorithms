#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int minSwaps(vector<int> &nums)
{
    // Code here

    int n = nums.size();

    vector<pair<int, int>> pairArr;  // <element , index> 

    for (int i = 0; i < n; i++)
    {
        pairArr.push_back({nums[i], i});
    }

    sort(pairArr.begin(), pairArr.end());

    int ans = 0;

    vector<bool> isVis(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (isVis[i] == true or pairArr[i].second == i)   // if element is visited or pairIdx == actal index (means it is at right position)
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

        ans += (cycleLen - 1);
    }

    return ans;
}

int main()
{

    return 0;
}