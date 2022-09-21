#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int minSubset(vector<int> &v, int n)
{

    sort(v.begin(), v.end());

    long long s = 0;

    s = accumulate(v.begin(), v.end(), s);

    long long curr = 0;

    for (int i = n - 1; i >= 0; i--)

    {
        curr += v[i];

        if (curr > (s - curr))

        {

            return n - i;
        }
    }
}
