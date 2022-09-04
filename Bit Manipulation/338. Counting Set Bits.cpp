#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Kernighan's Algorithm

int countBits(int n)
{
    int counter = 0;

    while (n != 0)
    {
        int rmsb = n & -n;
        n = n - rmsb;
        counter++;
    }

    return counter;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}