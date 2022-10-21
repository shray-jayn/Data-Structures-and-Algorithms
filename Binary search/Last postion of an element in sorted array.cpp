#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {5, 7, 7, 8, 8, 10};
    int n = 6;
    int target = 8;

    int s = 0, e = n - 1, m, ans;

    while (s <= e)
    {
        m = s + (e - s) / 2;
        if (a[m] == target)
        {
            ans = m;
            s = m + 1;
        }

        else if (a[m] > target)
        {
            e = m - 1;
        }

        else
        {
            s = m + 1;
        }
    }

    cout << ans << endl;
    return 0;
}