#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maxSumHelper(vector<vector<int>> &matrix, int i, int j, int n)
{

    if (i < 0 || j < 0 || i > n || j > n)  // out of range
    {
        return INT_MAX;
    }

    if (i == n - 1 or j == n - 1)  // base condition 
    {
        return matrix[i][j];
    }

    int down = maxSumHelper(matrix, i + 1, j, n);
    int down_left = maxSumHelper(matrix, i + 1, j - 1, n);
    int down_right = maxSumHelper(matrix, i + 1, j + 1, n);

    int ans = matrix[i][j] + min(down, min(down_left, down_right));

    return ans;
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    int i = 0;
    int j = 0;

    int ans = 0;

    for (i = 0; i < n; i++)
    {
        int res = maxSumHelper(matrix, i, j, n);

        ans = max(ans, res);
    }

    return ans;
}

int main()
{

    return 0;
}