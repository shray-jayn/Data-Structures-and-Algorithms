#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int subarrayWithContiguous(vector<int> arr)
{
    int n = arr.size();
    int ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int minEle = arr[i];
        int maxEle = arr[i];

        unordered_set<int> checkDuplicate;

        checkDuplicate.insert(arr[i]);

        for (int j = i + 1; j < n; j++)
        {
            if (checkDuplicate.find(arr[j]) != checkDuplicate.end())
            {
                break;
            }
            else
            {
                checkDuplicate.insert(arr[j]);
            }

            minEle = min(minEle, arr[j]);
            maxEle = max(maxEle, arr[j]);

            if (maxEle - minEle == j - i)
            {
                int len = j - i + 1;

                ans = max(ans, len);
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}