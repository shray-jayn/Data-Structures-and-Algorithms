#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

long long int calculate(int arr[], int n)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    int count = 0;

    for (auto it : mp)
    {
        int val = it.second;
        count += ((val - 1) * val) / 2;
    }

    return count;
}

int main()
{

    return 0;
}