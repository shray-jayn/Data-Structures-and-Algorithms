#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void countSort(vector<vector<int>> &mat, int row, int col)
{
    int m = mat.size();
    int n = mat[0].size();

    int i = row;
    int j = col;

    vector<int> fMap(101, 0);

    while (i < m and j < n)
    {
        fMap[mat[i][j]]++;
        i++;
        j++;
    }

    i = row;
    j = col;

    for (int k = 1; k < fMap.size(); k++)
    {
        while (fMap[k] > 0)
        {
            mat[i][j] = k;
            i++;
            j++;
            fMap[k]--;
        }
    }
}

vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();

    for (int i = 0; i < m; i++)
    {
        countSort(mat, i, 0);
    }
    for (int i = 1; i < n; i++)
    {
        countSort(mat, 0, i);
    }

    return mat;
}

int main()
{

    return 0;
}