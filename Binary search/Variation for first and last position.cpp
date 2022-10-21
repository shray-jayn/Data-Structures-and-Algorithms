#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {2, 4, 10, 10, 10, 18, 20};
    int n = 7;
    int target = 10;

    int s = 0, e = n - 1, m, ans;

    while (s <= e)
    {
        m = s + (e - s) / 2;
        if (a[m] <= target)
        {
            ans = m;
           
            s = m + 1;
        }

        // else if (a[m] > target)
        // {
        //     e = m - 1;
        // }

        else
        {
            e = m - 1;
        }
    }
    cout << ans << endl;
    return 0;
}