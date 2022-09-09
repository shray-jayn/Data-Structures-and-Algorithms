#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> printFirstNegativeInteger(ll arr[], ll n, ll k)
{
    int i = 0, j = k;

    vector<ll> ans;

    queue<ll> q;

    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            q.push(arr[i]);
        }
    }

    if (q.size() == 0)
    {
        ans.push_back(0);
    }
    else
    {
        ans.push_back(q.front());
    }

    while (j < n)
    {
        if (q.front() == arr[i])
        {
            q.pop();
        }
        i++;
        if (arr[j] < 0)
        {
            q.push(arr[j]);
        }
        j++;

        if (q.size() == 0)
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(q.front());
        }
    }

    return ans;
}

int main()
{
    ll n = 5;
    ll c[n] = {-8, 2, 3, -6, 10};

    vector<ll> q = printFirstNegativeInteger(c, 5, 2);

    for (int i = 0; i < q.size(); i++)
    {
        cout << q[i] << " ";
    }

    return 0;
}