#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    queue<int> q;
    unordered_map<int, int> indegree;
    unordered_map<int, bool> isVisited;
    unordered_map<int, vector<int>> adj;

    vector<int> ans;

    int count = 0 ;

    // initialize indegree to 0  and visited = 0 ;

    for (int i = 0; i < numCourses; i++)
    {
        indegree[i] = 0;
        isVisited[i] = 0;
    }

    for (auto it : prerequisites)
    {
        int a = it[0], b = it[1];
        indegree[a]++;
        adj[b].push_back(a);
    }

    queue<int> q;

    for (auto it : indegree)
    {
        if (it.second == 0)
        {
            q.push(it.first);
        }
    }

    while (q.size() != 0)
    {
        int curr = q.front();

        q.pop();

        for (auto it : adj[curr])
        {
            indegree[it]--;

            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }

        ans.push_back(curr);
        count++;
    }

    if(count!= numCourses)
    {
        return {};
    }

    return ans ;

}

int main()
{

    return 0;
}