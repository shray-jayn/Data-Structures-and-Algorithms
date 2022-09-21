#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int minimumCostOfBreaking(vector<int> x, vector<int> y, int m, int n)
{
    sort(x.begin(), x.end(), greater<int>());
    sort(y.begin(), y.end(), greater<int>());

    int horizontalCount = 1;
    int verticalCount = 1;

    int i = 0;
    int j = 0;
    int ans = 0;

    while (i < m and j < m)
    {
        if (x[i] > y[j])
        {
            ans += x[i] * verticalCount;
            horizontalCount++;
            i++;
        }
        else
        {
            ans += y[j] * horizontalCount;
            verticalCount++;
            j++;
        }
    }

    while (i < m)
    {
        ans += x[i] * verticalCount;
        i++;
    }
    while (j < n)
    {
        ans += y[j] * horizontalCount;
        j++;
    }

    return ans;
}

int main()
{

    return 0;
}