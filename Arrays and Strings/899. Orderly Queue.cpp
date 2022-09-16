#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// First, this is string rotation.
// 12345 -> 23451 -> 34512 -> 45123 -> 51234
// I use number instead of letters to make it clear.

// If K == 1, we can only rotate the whole string.
// There are S.length different states and
// we return the lexicographically smallest string.

// If K > 1, it means we can:

// rotate the whole string,
// rotate the whole string except the first letter.
// 012345 -> 023451 -> 034512 -> 045123 -> 051234
// We can rotate i+1th big letter to the start (method 1),
// then rotate ith big letter to the end (method 2).
// 2XXX01 -> XXX012

// In this way, we can bubble sort the whole string lexicographically.
// So just return sorted string.

// C++:

string orderlyQueue(string S, int K)
{
    if (K > 1)
    {
        sort(S.begin(), S.end());
        return S;
    }

    string res = S;

    for (int i = 1; i < S.length(); i++)
    {
        res = min(res, S.substr(i) + S.substr(0, i));
    }
    
    return res;
}

int main()
{

    return 0;
}