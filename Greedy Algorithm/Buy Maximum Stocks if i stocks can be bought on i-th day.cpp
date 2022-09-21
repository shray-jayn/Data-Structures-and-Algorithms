#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int, int>> product;

    for (int i = 0; i < n; ++i)
    {
        product.push_back(make_pair(price[i], i + 1));
    }

    sort(product.begin(), product.end());

    int ans = 0;
    int i = 0;

    while (i < n)
    {
        if (k < product[i].first)
        {
            return ans;
        }

        int temp = min(product[i].second, (k / product[i].first));

        ans += temp;
        k -= temp * product[i].first;
        
        i++;
    }
    return ans;
}

int main()
{

    return 0;
}