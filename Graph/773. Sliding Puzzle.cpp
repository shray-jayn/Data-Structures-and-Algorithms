#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int slidingPuzzle(vector<vector<int>> &grid)
{
    string s = "";
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            s = s + to_string(grid[i][j]);
        }
    }
    string target = "123450";
    queue<string> q;
    q.push(s);
    int level = 0;
    unordered_map<string, bool> vis;
    vector<vector<int>> dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
    while (q.size() > 0)
    {
        int size = q.size();
        while (size--)
        {
            string temp = q.front();
            q.pop();
            if (temp == target)
                return level;
            int idx = -1;
            for (int i = 0; i < temp.size(); i++)
            {
                if (temp[i] == '0')
                {
                    idx = i;
                    break;
                }
            }
            vector<int> array = dir[idx];
            for (int i = 0; i < array.size(); i++)
            {
                string news = temp;
                swap(news[idx], news[array[i]]);
                if (vis.find(news) != vis.end())
                    continue;
                vis[news] = true;
                q.push(news);
            }
        }
        level++;
    }
    return -1;
}

int main()
{

    return 0;
}