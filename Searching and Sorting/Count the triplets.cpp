#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int countTriplet(int arr[], int n)
{
    sort(arr, arr + n);

    int count = 0;

    for (int i = n - 1; i >= 2; i--)
    {
        int left = 0;
        int right = i - 1;

        while (left < right)
        {
            if (arr[left] + arr[right] == arr[i])
            {
                count++;
                left++;
                right--;
            }
            else if (arr[left] + arr[right] < arr[i])
            {
                left++;
            }
            else
            {
                right++;
            }
        }
    }

    return count;
}

int main()
{

    return 0;
}