#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll countStrings(int n)
{
    vector<int> zeros(n + 1, 0);
    vector<int> ones(n + 1, 0);

    // base case

    zeros[0] = 0, zeros[1] = 1;
    ones[0] = 0, ones[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        zeros[i] = ones[i - 1];

        ones[i] = ones[i - 1] + zeros[i - 1];
    }

    return zeros[n] + ones[n];
}

int main()
{

    return 0;
}