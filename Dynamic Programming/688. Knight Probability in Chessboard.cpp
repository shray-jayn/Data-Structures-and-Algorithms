#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

double dp[26][26][101];
double knight(int n, int k, int row, int column)
{
    // base cases
    if (row < 0 || column < 0 || row >= n || column >= n)
    {
        return 0;
    }
    if (k == 0)
        return 1; // if k ie. no. of steps is 0 than the probabilty to have Knight on borad is 1
    if (dp[row][column][k])
    {
        return dp[row][column][k];
    }
    double sum = 0; // to find the sum

    sum = knight(n, k - 1, row - 2, column - 1) + knight(n, k - 1, row - 1, column - 2) +
          knight(n, k - 1, row + 2, column + 1) + knight(n, k - 1, row + 1, column + 2) +
          knight(n, k - 1, row - 2, column + 1) + knight(n, k - 1, row + 2, column - 1) +
          knight(n, k - 1, row - 1, column + 2) + knight(n, k - 1, row + 1, column - 2);
    sum /= 8;
    return dp[row][column][k] = sum;
}

double knightProbability(int n, int k, int row, int column)
{
    return knight(n, k, row, column);
}

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