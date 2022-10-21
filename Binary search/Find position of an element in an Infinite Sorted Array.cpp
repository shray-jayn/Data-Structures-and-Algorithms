#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int target = 11;

    int s = 0, e = 1, m, ans;

    while (a[e] < target)
    {

        if (a[e] < target)
        {
            int temp = e;
            e = 2 * e;
            s = temp;
        }
    }
    bool flag = 0;

    while (s <= e)
    {
        m = s + (e - s) / 2;

        if (a[m] == target)
        {
            break;
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

    cout << m << endl;
}