#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findUnsortedSubarray(vector<int> &nums)
{
    int n = nums.size();

    // search for the start pointer  (larger than min element in right)

    int minEle = INT_MAX;
    int start = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] > minEle) // curret element is greater than the minimum element in it's right
        {
            start = i;
        }

        else if (nums[i] < minEle) // if not just update the minimum element
        {
            minEle = nums[i];
        }
    }

    // search for end pointer (smaller than max element in left)

    int maxEle = INT_MIN;
    int end = n;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < maxEle) // curret element is greater than the minimum element in it's right
        {
            end = i;
        }

        else if (nums[i] > minEle) // if not just update the maximum element
        {
            maxEle = nums[i];
        }
    }

    // if no starting index found, that means the array is already sorted in ascending order
    if (start == -1)
    {
        return 0;
    }
    return end - start + 1; // number of elements between start and end index
}

int main()
{

    return 0;
}