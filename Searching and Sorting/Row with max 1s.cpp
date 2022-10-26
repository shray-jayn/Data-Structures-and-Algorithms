#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findRow(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int omax = 0;
    int r = 0;

    for (int i = 0; i < n; i++)
    {
        int coir = binarySearch(matrix, i, m); // count of 1 in ith row

        if (coir > omax)
        {
            omax = coir;
            r = i;
        }
    }

    return r;
}

int binarySearch(vector<vector<int>> &matrix, int row, int n)
{
    int low = 0;
    int high = n - 1;
    int fil = matrix[0].size();

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (matrix[row][mid] == 1)
        {
            fil = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    int count = matrix[0].size() - fil;
    return count;
}

int main()
{

    return 0;
}