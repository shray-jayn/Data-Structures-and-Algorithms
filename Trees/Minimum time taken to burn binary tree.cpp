#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node
{
    Node *left;
    Node *right;
    int val;
};

int findMaxDist(map<Node *, Node *> &mp, Node *target)
{
    queue<Node *> q;

    map<Node *, bool> vis;

    vis[target] = true;

    q.push(target);

    int maxi = 0;

    while (!q.empty())
    {
        int size = q.size();

        int fl = 0;

        for (int i = 0; i < size; i++)
        {
            auto node = q.front();
            q.pop();

            if (node->left != NULL and vis[node->left] != true)
            {
                fl = 1;
                vis[node->left] = true;
                q.push(node->left);
            }

            if (node->right != NULL and vis[node->right] != true)
            {
                fl = 1;
                vis[node->right] = true;
                q.push(node->right);
            }

            if (mp[node] != NULL and vis[mp[node]] != true)
            {
                fl = 1;
                vis[mp[node]] = true;
                q.push(mp[node]);
            }
        }

        if (fl == 1) // flag is 1 when we have actually burned any adj. node ;
        {
            maxi++;
        }
    }

    return maxi;
}

Node *bfsToMapParents(Node *root, map<Node *, Node *> &mp, int start)
{
    queue<Node *> q;

    q.push(root);

    Node *res;

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node->val == start)
        {
            res = node;
        }

        if (node->left)
        {
            q.push(node->left);
            mp[node->left] = node;
        }

        if (node->right)
        {
            q.push(node->right);
            mp[node->right] = node;
        }
    }

    return res;
}

int timeTOBurnTree(Node *root, int start)
{
    map<Node *, Node *> mp;

    Node *target = bfsToMapParents(root, mp, start); // returns pointer to the  location of the start node and also generates the parent map

    int maxi = findMaxDist(mp, target);
}
int main()
{

    return 0;
}