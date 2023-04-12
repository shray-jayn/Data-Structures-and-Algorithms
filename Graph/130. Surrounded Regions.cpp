#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(vector<vector<char>> &board, int i, int j, int n, int m)
{
    if (i >= n or i < 0 or j >= m or j < 0 or board[i][j] != 'O')
    {
        return;
    }
    board[i][j] = '#'; // mark as visited;

    dfs(board, i + 1, j, n, m);
    dfs(board, i - 1, j, n, m);
    dfs(board, i, j + 1, n, m);
    dfs(board, i, j - 1, n, m);
}

void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'O' and (i == 0 or j == 0 or i == n - 1 or j == m - 1))
            {
                dfs(board, i, j, n, m);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '#')
            {
                board[i][j] = 'O';
            }
            else
            {
                board[i][j] = 'X';
            }
        }
    }

    return;
}

int main()
{

    return 0;
}