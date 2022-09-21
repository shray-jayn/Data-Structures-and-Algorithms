#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int widhth, height, n;
        cin >> widhth >> height >> n;

        vector<int> row;
        vector<int> col;

        row.push_back(0);
        col.push_back(0);

        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;

            row.push_back(x);
            col.push_back(y);
        }

        row.push_back(widhth + 1);
        col.push_back(height + 1);

        sort(row.begin(), row.end());
        sort(col.begin(), col.end());

        int mx = 0;
        int my = 0;

        for (int i = 0; i < row.size() - 1; i++)
        {
            mx = max(mx, row[i + 1] - row[i] - 1);
            my = max(my, col[i + 1] - col[i] - 1);
        }

        cout << mx * my << endl;
    }

    return 0;
}