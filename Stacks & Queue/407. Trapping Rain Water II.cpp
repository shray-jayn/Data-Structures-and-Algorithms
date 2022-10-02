#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Cell
{
    int row;
    int column;
    int height;

    Cell(int row, int column, int height)
    {
        this->row = row;
        this->column = column;
        this->height = height;
    }
};

int trapRainWater(vector<vector<int>> &heightMap)
{
    int n = heightMap[0].size();
    int m = heightMap.size();

    priority_queue<Cell, vector<Cell>, greater<Cell>> pq; // min heap

    vector<vector<bool>> isVisisted(m, vector<bool>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 or j == 0 or i == m - 1 or j == n - 1) // add all boundary elements to pq and mark visited
            {
                pq.push({i, j, heightMap[i][j]});
                isVisisted[i][j] = true;
            }
        }
    }

    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int water = 0;

    while (pq.size() != 0)
    {
        Cell rem = pq.top();
        pq.pop();

        for (auto dir : directions)
        {
            int rowDash = rem.row + dir[0];
            int colDash = rem.column + dir[1];

            if (rowDash >= 0 and rowDash < m and colDash >= 0 and colDash < n and isVisisted[rowDash][colDash] == false)
            {
                int val = max(0, rem.height - heightMap[rowDash][colDash]); // agar kudka or neigb ka height differice 0 se zyada hai to wo store kar sakta hai

                water += val;

                if (heightMap[rowDash][colDash] >= rem.height)
                {
                    pq.push({rowDash, colDash, heightMap[rowDash][colDash]});
                }
                else // height choti hai to panni bhar denge islye purani height dalege
                {
                    pq.push({rowDash, colDash, rem.height});
                }

                isVisisted[rowDash][colDash] = true; // mark visited
            }
        }
    }

    return water;
}

int main()
{
    vector<vector<int>> heightMap = {{3, 3, 3, 3, 3}, {3, 2, 2, 2, 3}, {3, 2, 1, 2, 3}, {3, 2, 2, 2, 3}, {3, 3, 3, 3, 3}};

    cout << trapRainWater(heightMap) << endl;
}