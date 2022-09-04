#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int singleNumber(vector<int> &nums)
{
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        ans = ans ^ nums[i];
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}