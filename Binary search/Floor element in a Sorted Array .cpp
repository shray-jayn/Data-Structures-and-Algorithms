#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 8, 10, 11, 12, 19};
    int target = 8;

    int s = 0, e = v.size() - 1, m, ans;

    while (s <= e)
    {
        m = s + (e - s) / 2;

        if (v[m] > target)
        {
            
            e = m - 1;
        }

        else if (v[m] < target)
        {
            ans = m;
            s = m + 1;
        }

        else
        {
            cout << m << endl;
            break;
            return 0;
        }
    }

  //  cout << ans << endl;
    return 0;
}