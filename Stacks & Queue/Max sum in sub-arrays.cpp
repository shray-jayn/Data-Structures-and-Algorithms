#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

long long pairWithMaxSum(long long arr[], long long N)
{
    long long s = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (arr[i] + arr[i + 1] > s)
        {
            s = arr[i] + arr[i + 1];
        }
    }
    return s;
}

int main()
{

    return 0;
}