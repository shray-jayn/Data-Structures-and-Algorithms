#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findOnce(int arr[], int n)
{
    int s = 0;
    int end = n - 1;
    
    int ans;

    if (n == 1)
    {
        return arr[0];
    }

    while (s <= end)
    {
        int mid = s + (end - s) / 2;

        if ((mid == 0 && arr[mid] != arr[mid + 1]) || (mid == end && arr[mid] != arr[mid - 1]) || arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }

        else if (mid % 2 == 0 && arr[mid] == arr[mid - 1] || mid % 2 != 0 && arr[mid] == arr[mid + 1])
        {
            end = mid - 1;
        }

        else
        {
            s = mid + 1;
        }
    }

    return -1;
}

int main()
{

    return 0;
}