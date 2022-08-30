#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int trap(vector<int> &height)
{
    int n = height.size();

    vector<int> leftMax(n), rightMax(n);

    for (int i = 1; i < n; ++i)
    {
        leftMax[i] = max(height[i - 1], leftMax[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i)
    {
        rightMax[i] = max(height[i + 1], rightMax[i + 1]);
    }

    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        int waterLevel = min(leftMax[i], rightMax[i]);
        
        if (waterLevel >= height[i])
            ans += waterLevel - height[i];
    }
    return ans;
}
int main()
{
    // vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> height = {4, 2, 0, 3, 2, 5};
    cout << trap(height) << endl;
    return 0;
}