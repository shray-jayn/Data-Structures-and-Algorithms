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

TreeNode *searchBST(TreeNode *root, int val, int &ceil)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->val == val)
    {
        return root;
    }

    else if (root->val > val)
    {
        ceil = root->val;
        return searchBST(root->left, val, ceil);
    }

    return searchBST(root->right, val, ceil);
}

int main()
{

    return 0;
}