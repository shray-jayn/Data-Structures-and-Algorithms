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

vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }

    vector<vector<int>> result;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int sz = q.size();
        vector<int> ans;

        while (sz--)
        {
            auto curr = q.front();

            ans.push_back(curr->val);

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }

            q.pop();
        }

        result.push_back(ans);
    }

    reverse(result.begin(), result.end());

    return result;
}

int main()
{

    return 0;
}