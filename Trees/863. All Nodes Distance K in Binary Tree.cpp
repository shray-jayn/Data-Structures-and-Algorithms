#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void markParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track, TreeNode *target)
{
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        if (curr->left)
        {
            parent_track[curr->left] = curr;
            q.push(curr->left);
        }

        if (curr->right)
        {
            parent_track[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode *, TreeNode *> parent_track; // node -> parent

    markParent(root, parent_track, target); // mark all the parents ;

    unordered_map<TreeNode *, bool> visited;

    queue<TreeNode *> q;

    q.push(target);

    visited[target] = true;

    int curr_lvl = 0;

    while (!q.empty())
    {
        int size = q.size();

        if (curr_lvl == k)
        {
            break;
        }

        curr_lvl++;

        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = q.front();

            q.pop();

            // check for left node
            if (curr->left and visited[curr->left] == false)
            {
                visited[curr->left] = true;
                q.push(curr->left);
            }

            // check for right node
            if (curr->right and visited[curr->right] == false)
            {
                visited[curr->right] = true;
                q.push(curr->right);
            }

            // Check for parent node
            if (parent_track[curr] and visited[parent_track[curr]] == false)
            {
                visited[parent_track[curr]] = true;
                q.push(parent_track[curr]);
            }
        }
    }

    vector<int> result;

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        result.push_back(curr->val);
    }

    return result;
}
int main()
{

    return 0;
}