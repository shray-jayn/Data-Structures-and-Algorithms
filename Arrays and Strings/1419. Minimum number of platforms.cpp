#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findPlatform(vector<int> &arr, vector<int> &dep, int n)
{
    int n = arr.size();

    // 1. Sort Arrival and Depatrue!

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    // 2. Maintain maxTrain at a particular time

    int i = 0; // points on arr time
    int j = 0; // points on dep time
    int maxTrain = 0;
    int minPlatform = 0;

    while (i < n and j < n)
    {
        if (arr[i] <= dep[j])
        {
            maxTrain++;
            i++;
        }
        else
        {
            maxTrain--;
            j++;
        }

        minPlatform = max(minPlatform, maxTrain);
    }

    return minPlatform;
}

int main()
{

    return 0;
}