#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    int mpist = 0; // max profit if sold today

    int leastSoFar = prices[0];

    vector<int> dp_mpsut(n, 0); // dp of maximum profit sold upto today

    for (int i = 1; i < n; i++)
    {
        if (prices[i] < leastSoFar)
        {
            leastSoFar = prices[i];
        }

        mpist = prices[i] - leastSoFar;

        if (mpist > dp_mpsut[i - 1])
        {
            dp_mpsut[i] = mpist;
        }
        else
        {
            dp_mpsut[i] = dp_mpsut[i - 1];
        }
    }

    // now solving in (right to left)

    int mpibt = 0; // Maximum profit if bought today

    vector<int> dp_mp_onRight(n, 0); // dp of maximum profit on right

    int maxAfterToday = prices[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        if (prices[i] > maxAfterToday)
        {
            maxAfterToday = prices[i];
        }

        mpibt = maxAfterToday - prices[i];

        if (mpibt > dp_mp_onRight[i + 1])
        {
            dp_mp_onRight[i] = mpibt;
        }
        else
        {
            dp_mp_onRight[i] = dp_mp_onRight[i + 1];
        }
    }

    int op = 0; // overall Profit

    for (int i = 0; i < n; i++)
    {
        if (dp_mp_onRight[i] + dp_mpsut[i] > op)
        {
            op = dp_mp_onRight[i] + dp_mpsut[i];
        }
    }

    return op;
}

int main()
{

    return 0;
}