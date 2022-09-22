#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int minTotalDist(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    // 1. Get X coordinates -> Row wise

    vector<int> xCord;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                xCord.push_back(i);
            }
        }
    }

    // 2. Get Y coordinates -> Col wise

    vector<int> yCord;

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (grid[i][j] == 1)
            {
                yCord.push_back(j);
            }
        }
    }

    // 3. Get mid -> best meeting point

    int x = xCord[xCord.size() / 2];
    int y = yCord[yCord.size() / 2];

    // 4. Calculate Dist -> min dist(due to median)

    int dist = 0;

    for (int i = 0; i < xCord.size(); i++)
    {
        dist += abs(x - xCord[i]);
    }

    for (int i = 0; i < yCord.size(); i++)
    {
        dist += abs(y - yCord[i]);
    }

    // Retuen ans

    return dist;
}

int main()
{

    return 0;
}