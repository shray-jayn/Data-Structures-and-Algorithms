#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    if (startRow >= m or startRow < 0 or startColumn >= n or startColumn < 0)
    {
        return 1;
    }

    if (maxMove == 0)
    {
        return 0;
    }

    int paths = findPaths(m, n, maxMove - 1, startRow + 1, startColumn) +
                findPaths(m, n, maxMove - 1, startRow - 1, startColumn) +
                findPaths(m, n, maxMove - 1, startRow, startColumn - 1) +
                findPaths(m, n, maxMove - 1, startRow, startColumn + 1);

    return paths;
}

int main()
{

    return 0;
}