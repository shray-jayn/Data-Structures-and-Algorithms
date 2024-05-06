#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

long long matrixSumQueries(int n, vector<vector<int>> &queries)
{
    int rowSeenCount = 0, colSeenCount = 0;

    vector<bool> rowSeen(n), colSeen(n);

    long long sum = 0;

    for (int qi = queries.size() - 1; qi >= 0; qi--)
    {
        int type = queries[qi][0];
        int index = queries[qi][1];
        int val = queries[qi][2];
        
        if (type == 0 && !rowSeen[index])
        {
            rowSeenCount++;
            rowSeen[index] = true;

            sum += 1LL * (n - colSeenCount) * val;
        }

        if (type == 1 && !colSeen[index])
        {
            colSeenCount++;
            colSeen[index] = true;

            sum += 1LL * (n - rowSeenCount) * val;
        }
    }

    return sum;
    
}

int main()
{

    return 0;
}