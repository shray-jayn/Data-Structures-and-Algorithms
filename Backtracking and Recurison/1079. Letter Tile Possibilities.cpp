#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int numTilePossibilities(string tiles)
{

    set<string> answer;

    unordered_map<int, bool> visited;

    for (int i = 0; i < tiles.length(); i++)
    {
        visited[i] = false;
    }

    string path = "";

    backtrack(tiles, answer, path, visited);

    return answer.size() - 1;
}

void backtrack(string tiles, set<string> &answer, string path, unordered_map<int, bool> &visited)
{

    answer.insert(path);

    for (int i = 0; i < tiles.length(); i++)
    {

        if (visited[i] == true)
        {
            continue;
        }

        path.push_back(tiles[i]);

        visited[i] = true;

        backtrack(tiles, answer, path, visited);

        visited[i] = false;

        path.pop_back();
    }
}