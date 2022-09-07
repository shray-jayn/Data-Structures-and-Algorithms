#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int copySetBitInRange(int num1, int num2, int left, int right)
{
    int mask1 = 1;

    int gap = right - left + 1;

    mask1 = 1 << gap;
    mask1--;

    mask1 = mask1 << (left - 1);

    mask1 = (num1 & mask1);

    num2 = num2 or mask1;

    return num2;
}

int main()
{

    return 0;
}