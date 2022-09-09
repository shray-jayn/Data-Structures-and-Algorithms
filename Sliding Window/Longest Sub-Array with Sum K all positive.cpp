// when all intergers are positive this works then

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int lenOfLongSubarr(int arr[], int n, int k)
{
    int i = 0, j = 0, sum = 0, count = 0;

    int maxLen = 0;

    while (j < n)
    {
        sum += arr[j];

        if (sum < k)
        {
            j++;
        }

        else if (sum == k)
        {
            maxLen = max(maxLen, j - i + 1);
            count++;
            j++;
        }

        else if (sum > k)
        {
            while (sum > k)
            {
                sum = sum - arr[i];
                i++;
            }
            j++;
        }
    }

    return maxLen;
}

int main()
{
    // int arr[] = {10, 5, 2, 7, 1, 9};
    // int arr[] = {-1, 2, 3};
    int arr[] = {-13, 0, 6, 15, 16, 2, 15, -12, 17, -16, 0, -3, 19, -3, 2, -9, -6};
    cout << lenOfLongSubarr(arr, 17, 15) << endl;

    return 0;
}