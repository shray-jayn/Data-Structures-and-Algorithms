#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int smallestDivisor(vector<int> &A, int threshold)
{
    int left = 1;
    int right = 1e6;
    int m;
    int sum;

    while (left < right)
    {
        m = (left + right) / 2;

        sum = 0;

        for (int i : A)
        {
            sum += (i + m - 1) / m;
        }

        if (sum > threshold)
        {
            left = m + 1;
        }

        else
        {
            right = m;
        }
    }

    return left;
}

int main()
{

    return 0;
}