#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{

    bool inBounds(int a, int b, int &m, int &n)
    { // Checking if the indices a and b are valid
        return a >= 0 && a < m && b >= 0 && b < n;
    }


public:

    int islandPerimeter(vector<vector<int>> &grid)
    {
        int perimeter = 0, m = grid.size(), n = grid[0].size();

        pair<int, int> start = {-1, -1};

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                { // Finding the starting position(or the first '1' that is encountered)
                    start = {i, j};
                    break;
                }
            }
            if (start.first != -1)
                break;
        }

        queue<pair<int, int>> Q;

        Q.push(start);
        grid[start.first][start.second] = -1; // Marking a position as visited
        // Standard BFS Traversal

        while (!Q.empty())
        {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            int sides = 4;


            if (inBounds(x + 1, y, m, n) && grid[x + 1][y] != 0)
            {
                if (grid[x + 1][y] == 1)
                    Q.push({x + 1, y});
                grid[x + 1][y] = -1;
                sides--;
            }


            if (inBounds(x - 1, y, m, n) && grid[x - 1][y] != 0)
            {
                if (grid[x - 1][y] == 1)
                    Q.push({x - 1, y}); // If position is not visited and it is a '1'
                grid[x - 1][y] = -1;
                sides--;
            }

            if (inBounds(x, y + 1, m, n) && grid[x][y + 1] != 0)
            {
                if (grid[x][y + 1] == 1)
                    Q.push({x, y + 1});
                grid[x][y + 1] = -1;
                sides--;
            }

            if (inBounds(x, y - 1, m, n) && grid[x][y - 1] != 0)
            {
                if (grid[x][y - 1] == 1)
                    Q.push({x, y - 1});
                grid[x][y - 1] = -1;
                sides--;
            }

            perimeter += sides;
        }
        
        return perimeter;
    }
};

int main()
{

    return 0;
}