#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Definition for a Node.
class Node
{
public:
  int val;
  vector<Node *> neighbors;
  Node()
  {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val)
  {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors)
  {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution
{
public:
  Node *cloneGraph(Node *node)
  {

    if (node == NULL)
    {
      return NULL;
    }

    unordered_map<Node *, Node *> visited;

    queue<Node *> q;
    visited[node] = new Node(node->val);

    while (!q.empty())
    {
      Node *curr = q.front();
      q.pop();

      for (auto it : curr->neighbors)
      {
        if (!visited[it])
        {
          visited[it] = new Node(it->val);
          q.push(it);
        }
        visited[curr]->neighbors.push_back(visited[it]);
      }
    }

    return visited[node];
  }
};

int main()
{

  return 0;
}