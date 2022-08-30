#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int distinctSubseqII(string s)
{
    int mod = 1000000007;
    int n = s.size();

    int dp[n + 1];

    dp[0] = 1;

    unordered_map<char, int> lastOcc;

    for (int i = 1; i < n + 1; i++)
    {
        char ch = s[i - 1];

        dp[i] = (2 * dp[i - 1]) % mod;

        if (lastOcc.find(ch) != lastOcc.end()) // repeat hua hai
        {
            int j = lastOcc[ch];

            dp[i] = (dp[i] - dp[j - 1]) % mod;
        }
        lastOcc[ch] = i % mod;
    }

    return dp[n] % mod;
}

int main()
{

    return 0;
}