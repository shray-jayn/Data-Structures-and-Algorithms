#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(int key, vector<int> &isVisited, vector<vector<int>> &rooms)
{

    isVisited[key] = 1;

    vector<int> room = rooms[key];

    for (int i = 0; i < room.size(); i++)
    {
        int newKey = room[i];

        if (isVisited[newKey] == 0)
        {
            dfs(newKey, isVisited, rooms);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    int n = rooms.size();

    vector<int> isVisited(n, 0);

    dfs(0, isVisited, rooms);

    for (int i = 0; i < n; i++)
    {
        if (isVisited[i] == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{

    return 0;
}