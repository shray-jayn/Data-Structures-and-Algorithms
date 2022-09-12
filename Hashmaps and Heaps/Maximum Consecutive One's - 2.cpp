#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int MaximumConsecutiveOnes(vector<int> arr)
{
    int n = arr.size();

    int ans = 0;
    int j = -1;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count++;
        }

        while (count > 1)
        {
            j++;

            if (arr[j] == 0)
            {
                count--;
            }
        }

        int len = i - j;

        ans = max(ans, len);    
    }

    return ans;
}

int main()
{

    return 0;
}