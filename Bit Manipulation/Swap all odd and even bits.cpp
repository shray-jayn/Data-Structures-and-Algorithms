#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int swapBits(int n)
{
    int oddMask = 0x55555555;
    int evenMask = 0xAAAAAAAA;

    int odds = (n & oddMask);
    int evens = (n & evenMask);

    odds = odds << 1;
    evens = evens >> 1;

    n = odds or evens;

    return n;
}

int main()
{

    return 0;
}