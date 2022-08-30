#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
    string alienOrder(vector<string> &words)
    {
        map<char, set<char>> graph = buildGraph(words);
        return topoSort(graph);
    }

    map<char, set<char>> buildGraph(vector<string> &words)
    {
        map<char, set<char>> graph;

        // create nodes for each of the char
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                char c = words[i][j];
                if (graph.count(c) == 0)
                {
                    graph[c] = set<char>();
                }
            }
        }

        // create edges
        for (int i = 0; i < words.size() - 1; ++i)
        {
            int index = 0;
            while (index < words[i].size() && index < words[i + 1].size())
            {
                if (words[i][index] != words[i + 1][index])
                {
                    graph[words[i][index]].insert(words[i + 1][index]);
                    break;
                }
                index++;
            }
        }
        return graph;
    }

    string topoSort(map<char, set<char>> &graph)
    {

        map<char, int> indegree = getIndegree(graph);
        priority_queue<char, vector<char>, greater<char>> queue;

        for (auto p : indegree)
        {
            if (p.second == 0)
            {
                queue.push(p.first);
            }
        }
        string res;
        while (queue.empty() == false)
        {
            char c = queue.top();
            queue.pop();
            res += c;
            for (auto &ch : graph[c])
            {
                indegree[ch]--;
                if (indegree[ch] == 0)
                {
                    queue.push(ch);
                }
            }
        }
        return (res.size() != indegree.size()) ? "" : res;
    }

    map<char, int> getIndegree(map<char, set<char>> &graph)
    {
        map<char, int> indegree;
        for (auto &p : graph)
        {
            indegree[p.first] = 0;
        }

        for (auto &p : graph)
        {
            for (char c : p.second)
            {
                indegree[c]++;
            }
        }
        return indegree;
    }
};

int main()
{

    return 0;
}