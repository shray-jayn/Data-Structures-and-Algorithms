#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> candyStore(int candies[], int n, int k)
{
    sort(candies, candies + n);

    int mx = 0, mn = 0;

    int i = 0, j = n - 1;

    while (i <= j)
    {
        mn += candies[i];

        i++;
        j = j - k;
    }

    reverse(candies, candies + n);

    i = 0, j = n - 1;

    while (i <= j)
    {
        mx += candies[i];

        i++;
        j = j - k;
    }

    return {mn, mx};
}

int main()
{

    return 0;
}