#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int minFlips(string target)
{
    int n = target.size();
    int ans = 0;
    int future = 0;

    for (int i = 0; i < n; i++)
    {
        if (future == target[i] - '0')
        {
            continue;
        }
        else
        {
            ans++;

            future = (future == 0) ? 1 : 0;
        }
    }

    return ans;
}

int main()
{

    return 0;
}