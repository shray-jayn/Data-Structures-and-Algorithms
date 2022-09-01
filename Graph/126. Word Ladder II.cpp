#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<string>> paths;

void dfs(string startWord, string endWord, vector<string> path, unordered_map<string, unordered_set<string>> &adj, int len)
{
    path.push_back(startWord);

    if (path.size() > len)
    {
        return;
    }

    if (startWord == endWord and path.size() == len)
    {
        paths.push_back(path);
        path.pop_back();
        return;
    }

    for (auto it : adj[startWord])
    {
        dfs(it, endWord, path, adj, len);
    }

    path.pop_back();
}

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        return 0;
    set<string> s;
    for (auto i : wordList)
        s.insert(i);
    queue<string> q;
    q.push(beginWord);
    int d = 0;
    while (!q.empty())
    {
        d++;
        int n = q.size();
        while (n--)
        {
            string curr = q.front();
            q.pop();
            for (int i = 0; i < curr.length(); i++)
            {
                string tmp = curr;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    tmp[i] = c;
                    if (tmp == curr)
                        continue;
                    if (tmp == endWord)
                        return d + 1;
                    if (s.find(tmp) != s.end())
                    {
                        q.push(tmp);
                        s.erase(tmp);
                    }
                }
            }
        }
    }
    return 0;
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
}

int main()
{

    return 0;
}