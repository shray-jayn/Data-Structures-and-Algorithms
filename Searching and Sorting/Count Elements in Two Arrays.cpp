#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int binarySearch(int key, vector<int> arr, int n)
{
    int count = 0;

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= key)
        {
            count += (mid - low + 1);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return count;
}

// T.C. -> O(Nlog(M))  using binary search!

vector<int> find(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    sort(arr2.begin(), arr2.end());

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        int key = arr1[i];
        int count = binarySearch(key, arr2, m);

        ans[i] = count;
    }

    return ans;
}

// T.C. O(N) , S.C. O(1) using freqTable and Prefix Sum!

vector<int> find(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    vector<int> freqArr(100000, 0);

    for (int i = 0; i < m; i++)
    {
        freqArr[arr2[i]]++;
    }

    vector<int> prefixSum(100000, 0);

    for (int i = 1; i < prefixSum.size(); i++)
    {
        prefixSum[i] = prefixSum[i - 1] + freqArr[i];
    }

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        int key = arr1[i];
        ans[i] = prefixSum[key];
    }

    return ans;
}

int main()
{

    return 0;
}