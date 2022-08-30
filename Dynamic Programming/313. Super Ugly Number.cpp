#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// O(n*k) TC

int nthSuperUglyNumber(int n, vector<int> &primes)
{
    int m = primes.size();

    vector<int> dp(n + 1, 0);

    vector<int> pointers(m, 1); // all pointers initially pointing to 1

    for (int i = 2; i <= n; i++)
    {
        int minVal = INT_MAX;

        for (int j = 0; j < m; j++)
        {
            int val = primes[j] * dp[pointers[j]];
            minVal = min(val, minVal);
        }

        dp[i] = minVal;

        for (int j = 0; j < m; j++)
        {
            if (minVal = primes[j] * dp[pointers[j]])
            {
                pointers[j]++;
            }
        }
    }

    return dp[n];
}

// Optimized O(n*log(k))  TC

typedef pair<long long, pair<long long, long long>> ppi;

class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        priority_queue<ppi, vector<ppi>, greater<ppi>> minh; // min heap of pairs {values, prime No, index of dp}
        long long dp[n];
        dp[0] = 1; // 1 is the first ugly number
        for (auto &i : primes)
        {
            minh.push({i, {i, 0}}); // {value,{prime No,index}}
        }
        for (int i = 1; i < n;)
        {
            auto it = minh.top();
            minh.pop();
            long long prime = it.second.first; // current prime no.
            long long ind = it.second.second;  // index
            long long val = it.first;          // next minimum ugly number (prime no. * dp[ind])
            if (dp[i - 1] != val)
                dp[i++] = val; // to not allow repeatation of same ugly number
            ind++;             // incrementing the index
            it.second.second = ind;
            it.first = prime * dp[ind]; // the updated value
            minh.push(it);              // inserting in heap after updating
        }
        return dp[n - 1]; // returning nth ugly number
    }
};

int main()
{

    return 0;
}