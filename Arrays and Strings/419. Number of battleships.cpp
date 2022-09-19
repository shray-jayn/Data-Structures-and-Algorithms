#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    
    void bfs(int r, int c, int n, int m, vector<vector<char>> &board)
    {
        board[r][c] = '.';
        queue<pair<int, int>> q;
        q.push({r, c});
        while (!q.empty())
        {
            int i = q.front().first, j = q.front().second;
            q.pop();
            for (int d = 0; d < 4; d++)
            {
                int ni = i + dir[d], nj = j + dir[d + 1];
                if (ni < n && nj < m && ni > -1 && nj > -1 && board[ni][nj] == 'X')
                {
                    board[ni][nj] = '.';
                    q.push({ni, nj});
                }
            }
        }
        return;
    }
    int countBattleships(vector<vector<char>> &board)
    {
        int cnt = 0;
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'X')
                {
                    cnt++;
                    bfs(i, j, n, m, board);
                }
            }
        return cnt;
    }
};
// dfs approach
class Solution
{
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    void dfs(int r, int c, int n, int m, vector<vector<char>> &board)
    {
        if (r >= n || c >= m || r < 0 || c < 0 || board[r][c] != 'X')
            return;
        board[r][c] = '.';
        for (int d = 0; d < 4; d++)
        {
            dfs(r + dir[d], c + dir[d + 1], n, m, board);
        }
    }
    int countBattleships(vector<vector<char>> &board)
    {
        int cnt = 0;
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'X')
                {
                    cnt++;
                    dfs(i, j, n, m, board);
                }
            }

        return cnt;
    }
};

int main()
{

    return 0;
}