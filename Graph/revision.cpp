#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(vector<vector<char>> &grid, int i, int j, int row, int col)
{
    if (i < 0 or i >= row or j < 0 or j >= col)
    {
        return;
    }
    if (grid[i][j] == '2' or grid[i][j] == '0')
    {
        return;
    }

    grid[i][j] = '2';

    dfs(grid, i + 1, j, row, col);
    dfs(grid, i - 1, j, row, col);
    dfs(grid, i, j + 1, row, col);
    dfs(grid, i, j - 1, row, col);
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                dfs(grid, i, j, n, m);
                count++;
            }
        }
    }

    return count;
}

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();

    queue<pair<int, int>> q;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push({i, j});
            }

            else if (mat[i][j] == 1)
            {
                mat[i][j] = -1;
            }
        }
    }

    int dist = 1;

    while (!q.empty())
    {
        int size = q.size();

        for (int k = 0; k < size; k++)
        {
            auto curr = q.front();
            q.pop();

            int i = curr.first;
            int j = curr.second;

            // top

            if (i > 0 and mat[i - 1][j] == -1)
            {
            }

            // bottom
            if (i < row - 1 and mat[i + 1][j] == -1)
            {
            }
            // left
            if (j > 0 and mat[i][j - 1] == -1)
            {
            }
            // right
            if (j > col - 1 and mat[i][j + 1] == -1)
            {
            }
        }

        dist++;
    }
}

void dfs1(vector<vector<int>> &grid, vector<vector<int>> &cell, int i, int j, int row, int col, queue<pair<int, int>> &bfs)
{

    if (i < 0 or i >= row or j < 0 or j >= col)
    {
        return;
    }

    grid[i][j] = -1; // mark visited
    cell[i][j] = 0;  // inital dist

    bfs.push({i, j});

    dfs1(grid, cell, i + 1, j, row, col, bfs);
    dfs1(grid, cell, i - 1, j, row, col, bfs);
    dfs1(grid, cell, i, j + 1, row, col, bfs);
    dfs1(grid, cell, i, j - 1, row, col, bfs);
}

int shortestBridge(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> cell(n, vector<int>(m, -1));

    bool flag = 0;

    queue<pair<int, int>> bfs;

    for (int i = 0; i < n; i++)
    {
        if (flag == 1)
        {
            break;
        }

        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                flag = 1;
                dfs1(grid, cell, i, j, n, m, bfs);
                break;
            }
        }
    }

    int dist = 1;
    int minDist = INT_MAX;

    while (!bfs.empty())
    {
        int size = bfs.size();

        for (int k = 0; k < size; k++)
        {
            auto cur = bfs.front();
            bfs.pop();

            int i = cur.first;
            int j = cur.second;

            // top

            if (i > 0 and cell[i - 1][j] == -1)
            {
                cell[i - 1][j] = dist;

                if (grid[i - 1][j] == 1)
                {
                    minDist = min(minDist, dist);
                }

                bfs.push({i - 1, j});
            }

            // bottom

            // left

            // right
        }

        dist++;
    }
}

int slidingPuzzle(vector<vector<int>> &board)
{
    int row = board.size();
    int col = board[0].size();

    string src = "";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int val = board[i][j];
            src = src + to_string(val);
        }
    }

    string target = "123450";

    queue<string> bfs;

    vector<vector<int>> dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {0, 3}};
    unordered_map<string, bool> isVisited;

    bfs.push(src);
    isVisited[src] = true;

    int levels = 0;

    while (!bfs.empty())
    {
        int len = bfs.size();

        while (len--)
        {
            auto cur = bfs.front();
            bfs.pop();

            if (cur == target)
            {
                return levels;
            }

            int idx = -1;

            for (int i = 0; i < cur.size(); i++)
            {
                if (cur[i] == '0')
                {
                    idx = i;
                    break;
                }
            }

            vector<int> arr = dir[idx];

            for (int i = 0; i < arr.size(); i++)
            {
                int val = arr[i];
                string temp = cur;

                swap(temp[val], temp[idx]);

                if (isVisited.find(temp) == isVisited.end())
                {
                    bfs.push(temp);
                    isVisited[temp] = true;
                }
            }
        }

        levels++;
    }

    return -1;
}

int minSwaps(vector<int> &nums)
{
    int n = nums.size();

    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++)
    {
        arr.push_back({nums[i], i});
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    vector<bool> idVisited(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (arr[i].second == i)
        {
            continue;
        }

        else // chain starts
        {
            int idx = arr[i].second;
        }
    }
}

vector<vector<int>> adj;

void topologicalSort(int x, vector<bool> &visited, stack<int> &s)
{
    if (visited[x] == false)
    {
        visited[x] = true;

        for (int i = 0; i < adj[x].size(); i++)
        {
        }
    }
}

string findOrder(string dict[], int n, int k)
{
}




int main()
{

    return 0;
}