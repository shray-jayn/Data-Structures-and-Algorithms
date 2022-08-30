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

// USING DFS

void dfs(TreeNode *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (ans.size() < level)
    {
        ans.push_back(root->val);
    }

    dfs(root->right, ans, level + 1);

    dfs(root->left, ans, level + 1);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;

    dfs(root, ans, 1);

    return ans;
}

// USING BFS

vector<int> rightSideView(TreeNode *root)
{
    vector<int> v;

    if (root == NULL)
        return v;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int count = q.size();

        for (int i = 0; i < count; i++)
        {
            TreeNode *curr = q.front();
            q.pop();

            if (i == count - 1)
                v.push_back(curr->val);

            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
                
        }
    }
    return v;
}

int main()
{

    return 0;
}