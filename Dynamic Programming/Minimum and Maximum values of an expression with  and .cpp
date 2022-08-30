#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int MCMmin(int i, int j, string s)
{

    if (i > j) // 0 element left
    {
        return 0;
    }

    if (i == j) // only 1 element left
    {
        return s[i] - '0';
    }

    int ans = INT_MAX;

    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int tempAns;

        if (s[k] == '+')
        {
            tempAns = MCMmin(i, k - 1, s) + MCMmin(k + 1, j, s);
        }
        if (s[k] == '*')
        {
            tempAns = MCMmin(i, k - 1, s) * MCMmin(k + 1, j, s);
        }

        ans = min(ans, tempAns);
    }

    return ans;
}

int MCMmax(int i, int j, string s)
{
    if (i > j) // 0 element left
    {
        return 0;
    }

    if (i == j) // only 1 element left
    {
        return s[i] - '0';
    }

    int ans = INT_MIN;

    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int tempAns;

        if (s[k] == '+')
        {
            tempAns = MCMmax(i, k - 1, s) + MCMmax(k + 1, j, s);
        }
        if (s[k] == '*')
        {
            tempAns = MCMmax(i, k - 1, s) * MCMmax(k + 1, j, s);
        }

        ans = max(ans, tempAns);
    }

    return ans;
}

int main()
{

    return 0;
}