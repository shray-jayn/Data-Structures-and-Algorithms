#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isValid(int ni, int nj, int n)
{
    if (ni >= 0 and nj >= 0 and nj < n and ni < n)
    {
        return true;
    }

    return false;
}

void solve(int row, int col, int n, int k)
{
}

double knightProbability(int n, int k, int row, int col)
{
    vector<vector<double>> curr(n, vector<double>(n, 0));
    vector<vector<double>> next(n, vector<double>(n, 0));

    curr[row][col] = 1;

    for (int moves = 1; moves <= k; moves++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (curr[i][j] != 0)
                {
                    int next_i = 0;
                    int next_j = 0;

                    next_i = i - 2, next_j = j + 1;

                    if (isValid(next_i, next_j, n))
                    {
                        next[next_i][next_j] += curr[i][j] / 8.0;
                    }

                    next_i = i - 1, next_j = j + 2;

                    if (isValid(next_i, next_j, n))
                    {
                        next[next_i][next_j] += curr[i][j] / 8.0;
                    }

                    next_i = i + 2, next_j = j + 1;
                    if (isValid(next_i, next_j, n))
                    {
                        next[next_i][next_j] += curr[i][j] / 8.0;
                    }

                    next_i = i + 2, next_j = j - 1;
                    if (isValid(next_i, next_j, n))
                    {
                        next[next_i][next_j] += curr[i][j] / 8.0;
                    }

                    next_i = i - 2, next_j = j + 1;
                    if (isValid(next_i, next_j, n))
                    {
                        next[next_i][next_j] += curr[i][j] / 8.0;
                    }

                    next_i = i + 1, next_j = j - 2;
                    if (isValid(next_i, next_j, n))
                    {
                        next[next_i][next_j] += curr[i][j] / 8.0;
                    }

                    next_i = i - 1, next_j = j - 2;
                    if (isValid(next_i, next_j, n))
                    {
                        next[next_i][next_j] += curr[i][j] / 8.0;
                    }

                    next_i = i - 2, next_j = j - 1;
                    if (isValid(next_i, next_j, n))
                    {
                        next[next_i][next_j] += curr[i][j] / 8.0;
                    }
                }
            }

            next = curr;

            curr;
        }
    }

    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += curr[i][j];
        }
    }

    return sum;
}

int main()
{

    return 0;
}