#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);

    int i = 0;
    int j = 1;

    while (i < size and j < size)
    {
        int diff = arr[j] - arr[i];

        if (diff == n)
        {
            return true;
        }

        else if (diff < n)
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    return false;
}

int main()
{

    return 0;
}