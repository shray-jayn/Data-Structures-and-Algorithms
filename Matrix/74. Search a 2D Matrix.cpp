#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int i = 0, j = m - 1;

    while (i <= n - 1 and j >= 0)
    {
        if (matrix[i][j] == target)
        {
            return true;
        }

        if (matrix[i][j] > target)
        {
            j--;
        }

        else if (matrix[i][j] < target)
        {
            i++;
        }
    }

    return false;
}

int main()
{

    return 0;
}