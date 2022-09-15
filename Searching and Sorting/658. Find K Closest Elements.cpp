#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Using Priority Queue O(Nlog(k)+klog(k))

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int n = arr.size();

    vector<int> ans;

    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push({abs(arr[i] - x), arr[i]});

        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    while (pq.size() > 0)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(), ans.end());

    return ans;
}

// Using Binary search

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int n = arr.size();

    int low = 0;
    int high = n - 1;
    int mid = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            break;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    int left = mid - 1;
    int right = mid;

    vector<int> ans;

    while (left >= 0 and right < n and k > 0)
    {
        int leftVal = abs(arr[left] - x);
        int rightVal = abs(arr[right] - x);

        if (leftVal <= rightVal)
        {
            ans.push_back(arr[left]);
            left--;
        }

        else
        {
            ans.push_back(arr[right]);
            right++;
        }

        k--;
    }

    ans.push_back(arr[mid]);

    while (k > 0 and left >= 0)
    {
        ans.push_back(arr[left]);
        left--;
        k--;
    }

    while (k > 0 and right < n)
    {
        ans.push_back(arr[right]);
        right++;
        k--;
    }

    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{

    return 0;
}