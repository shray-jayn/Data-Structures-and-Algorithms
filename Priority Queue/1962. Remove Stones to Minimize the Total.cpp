#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int minStoneSum(vector<int> &piles, int k)
{
    int n = piles.size();

    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(piles[i]);
    }

    while (k--)
    {
        int val = pq.top();
        pq.pop();
        val = ceil((float)val / (float)2);

        pq.push(val);
    }

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += pq.top();
        pq.pop();
    }

    return sum;
}

int main()
{
    vector<int> piles = {4, 3, 6, 7};
    int k = 3;

    cout << minStoneSum(piles, k) << endl;

    return 0;
}