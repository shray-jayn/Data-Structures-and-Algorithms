#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

long sumOfBitDifference(vector<int> arr)
{
    long n = arr.size();

    long res = 0;

    for (int i = 0; i < 32; i++)
    {
        long countOn = 0;

        for (int val : arr)
        {
            if (val & (1 << i) != 0) // bit is off
            {
                countOn++;
            }
        }

        long countOff = n - countOn;

        long diff = countOn * countOff * 2;

        res += diff;
    }

    return res;
}

int main()
{

    return 0;
}