#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

long long minCost(long long arr[], long long n)
{
    // Your code here

    priority_queue<ll, vector<ll>, greater<ll>> pq(arr, arr + n);

    ll cost = 0;

    while (pq.size() > 1)
    {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();

        ll new_rope = a + b;
        cost += new_rope;
        pq.push(new_rope);
    }

    return cost;
}

int main()
{

    return 0;
}