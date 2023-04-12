#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// FIxed size sliding window

int numOfSubarrays(vector<int> &arr, int k, int threshold)
{
    int n = arr.size();

    int i = 0, j = k;

    int sum = 0;
    int count = 0;

    int avg = 0;

    // acuire first window

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    avg = sum / k;

    if (avg >= threshold)
    {
        count++;
    }

    i = 0;

    while (j < n)
    {
        sum += arr[j];
        sum -= arr[i];

        i++;
        j++;

        avg = sum / k;
        if (avg >= threshold)
        {
            count++;
        }
    }

    return count;
}

int main()
{

    return 0;
}