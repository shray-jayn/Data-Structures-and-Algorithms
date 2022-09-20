#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int numOfSubarrays(vector<int> &arr)
{
    int n = arr.size();

    long long ans = 0;
    int even = 0;
    int odd = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum % 2 == 0)
        {
            ans += odd;
            even++;
        }
        else
        {
            ans += 1 + even;
            odd++;
        }
    }

    return (int)(ans % (1000000007));
}

int main()
{

    return 0;
}