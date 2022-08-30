#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maxCount(int m, int n, vector<vector<int>> &ops)
{
    for (auto e : ops)
    {
        m = min(m, e[0]);
        n = min(n, e[1]);
    }
    return m * n;
}

int main()
{

    return 0;
}