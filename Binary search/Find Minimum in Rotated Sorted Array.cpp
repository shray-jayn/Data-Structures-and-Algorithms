#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 8;

    int a[n] = {11, 12, 15, 18, 2, 5, 6, 8};

    if (a[0] < a[n - 1])
    {
        cout << a[0] << endl;
        return 0;
    }

    int s = 0, e = n - 1, m;

    bool flag = 0;

    m = s + (e - s) / 2;

    if (a[m] > a[e])
    {
        flag = 1;
        s = m + 1;
    }

    else if (a[m] < a[s])
    {
        flag = 0;
        e = m - 1;
    }

    if (flag)
    {
        while (s <= e)
        {
            m = s + (e - s) / 2;
            if (a[m] < a[m - 1] and a[m] < a[m + 1])
            {
                cout << m << endl;
                break;
            }

            else if (a[m] > a[m - 1] and a[m] < a[m - 1])
            {
                e = m - 1;
            }

            
        }
    }
}