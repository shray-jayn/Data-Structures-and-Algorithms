#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int n;
    cin >> n;
    int target;
    cin >> target;

    vector<ll> v;

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v.push_back(a);
    }

    vector<ll>::iterator i;

    i = lower_bound(v.begin(), v.end(), target);

    if (i - v.begin() - 1 < 0)
    {
        cout << "-1" << endl;
    }

    else
    {
        cout << i - v.begin()-1 << endl;
    }
}