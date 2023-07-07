#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int diagonalSum(vector<vector<int>> &mat)
{
    int n = mat.size();

    int sum = 0;

    for (int i = 0, j = 0; i < n, j < n; i++, j++)
    {
        sum += mat[i][j];

        mat[i][j] = -mat[i][j];
    }

    for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--)
    {
        if (mat[i][j] >= 0)
        {
            sum += mat[i][j];
            mat[i][j] = -mat[i][j];
        }
    }

    return sum;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout << diagonalSum(mat) << endl;

    return 0;
}