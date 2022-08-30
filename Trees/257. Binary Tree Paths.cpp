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

bool getPath(TreeNode *root, string s, vector<string> &ans)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->left == NULL and root->right == NULL)
    {
        s += to_string(root->val);
        ans.push_back(s);
        return true;
    }

    s += to_string(root->val) + "->";

    if (getPath(root->left, s, ans) == true or getPath(root->right, s, ans) == true)
    {
        return true;
    }
}

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ans;

    if (root == NULL)
    {
        return ans;
    }

    getPath(root, "", ans);

    return ans;
}

int main()
{

    return 0;
}