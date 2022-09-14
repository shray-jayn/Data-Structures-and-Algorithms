#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int i = 0, j = m - 1;
    
    while (i < n and j > -1)
    {
        if (matrix[i][j] == target)
        {
            return true;
        }
        else if (target < matrix[i][j])
        {
            j--;
        }
        else if (target > matrix[i][j])
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