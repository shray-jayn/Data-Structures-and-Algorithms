#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int inversions = 0;

vector<ll> merge2Sorted(vector<ll> left, vector<ll> right)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;

    int n = left.size();
    int m = right.size();

    vector<ll> merged(n + m);

    while (i < n and j < m)
    {
        if (left[i] <= right[j])
        {
            merged[k] = left[i];
            k++;
            i++;
        }
        else
        {
            count += (n - i);
            merged[k] = right[j];
            j++;
            k++;
        }
    }

    while (i < n)
    {
        merged[k] = left[i];
        k++;
        i++;
    }
    while (j < m)
    {
        merged[k] = right[j];
        j++;
        k++;
    }

    inversions += count;

    return merged;
}

vector<ll> mergeSort(vector<ll> arr, ll low, ll high)
{
    if (low == high)
    {
        return {arr[low]};
    }

    int mid = (high + low) / 2;

    vector<ll> left = mergeSort(arr, low, mid);
    vector<ll> right = mergeSort(arr, mid + 1, high);

    vector<ll> merged = merge2Sorted(left, right);

    return merged;
}

long long int inversionCount(vector<ll> arr, ll n)
{
    mergeSort(arr, 0, n - 1);

    return inversions;
}

int main()
{

    return 0;
}