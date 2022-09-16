#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int firstBadVersion(int n)
{
    int high = n;
    int low = 1;
    int bad;
    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (isBadVersion(mid))
        {
            bad = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return bad; 
}

int main()
{

    return 0;
}