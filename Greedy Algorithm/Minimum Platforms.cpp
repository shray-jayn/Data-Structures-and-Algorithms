#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findPlatform(int arr[], int dep[], int n)
{
    // Your code here

    sort(arr, arr + n);
    sort(dep, dep + n);

    int pt = 1;

    int i = 1, j = 0;
    while (i < n)
    {
        if (arr[i] <= dep[j])
        {
            pt++;
        }
        else
        {
            j++;
        }
        i++;
    }

    return pt;
}

int main()
{

    return 0;
}