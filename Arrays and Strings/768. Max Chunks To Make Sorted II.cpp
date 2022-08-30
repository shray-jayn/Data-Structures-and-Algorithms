#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maxChunksToSorted(vector<int> &arr)
{
    int N = arr.size();

    // Max[i]:Max value in range [0, i)

    vector<int> Max(N + 1, INT_MIN);

    for (int i = 1; i <= N; ++i)
    {
        Max[i] = max(Max[i - 1], arr[i - 1]);
    }

    // Min[i]:Min value in range [i,N)

    vector<int> Min(N + 1, INT_MAX);

    for (int i = N - 1; i >= 0; --i)
    {
        Min[i] = min(Min[i + 1], arr[i]);
    }

    // Calculate Chunks

    int nChunks = 0;

    for (int i = 1; i <= N; ++i)
    {
        // if max of range[0, i) <= min of range[i, N)
        // add 1 to number of chunks.

        nChunks += Max[i] <= Min[i];
    }
    
    return nChunks;
}

int main()
{

    return 0;
}