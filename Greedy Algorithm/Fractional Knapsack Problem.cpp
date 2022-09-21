#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

static bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] > b[1];
}

int maximumUnits(vector<vector<int>> &boxtypes, int truckSize)
{
    int totalSum = 0;

    sort(boxtypes.begin(), boxtypes.end(), cmp);

    int i = 0;

    while (truckSize > 0 && i < boxtypes.size())
    {
        // if weight is less than truckSize

        if (truckSize - boxtypes[i][0] > 0)
        {
            truckSize -= boxtypes[i][0];
            totalSum += (boxtypes[i][0] * boxtypes[i][1]);
        }

        // if weight is greater than truckSize
        else
        {
            totalSum += (truckSize * boxtypes[i][1]);
            truckSize = 0;
        }

        i++;
    }
    
    return totalSum;
}

int main()
{

    return 0;
}