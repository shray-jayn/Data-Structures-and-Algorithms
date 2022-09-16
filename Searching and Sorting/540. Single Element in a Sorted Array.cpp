#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();

    if (n == 1)
    {
        return arr[0];
    }

    if (arr[0] != arr[1])
    {
        return arr[0];
    }

    if (arr[n - 1] != arr[n - 2])
    {
        return arr[n - 1];
    }

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] != arr[mid + 1] and arr[mid] != arr[mid - 1])
        {
            return arr[mid];
        }

        else if (arr[mid] == arr[mid - 1])
        {
            int leftCount = (mid - low + 1);

            if (leftCount % 2 == 0)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 2;
            }
        }
        else if (arr[mid] == arr[mid + 1])
        {

            int rightCount = (high - mid + 1);

            if (rightCount % 2 == 0)
            {
                high = mid - 1;
            }
            else
            {
                high = mid + 2;
            }
        }
    }

    return -1;
}

int main()
{

    return 0;
}