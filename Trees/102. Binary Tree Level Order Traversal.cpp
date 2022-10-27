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

vector<vector<int>> levelOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }

    vector<vector<int>> ans;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int len = q.size();

        vector<int> row;

        while (len--)
        {
            auto temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                break;
            }

            if (temp != NULL)
            {
                int valu = temp->val;
                row.push_back(valu);
            }

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }

        ans.push_back(row);
    }

    return ans;
}

int main()
{

    return 0;
}