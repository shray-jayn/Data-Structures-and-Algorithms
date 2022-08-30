#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int numDecodings(string s)
{
    int n = s.size();

    vector<int> dp(n + 1, 0);

    dp[0] = 0; // check again

    if (s[0] == '0')
    {
        dp[1] = 0;
    }
    else
        dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (s[i] == '0')
        {
            dp[i] = 0;
        }
    }
}

int main()
{

    return 0;
}