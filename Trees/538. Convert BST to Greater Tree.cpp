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

int sum = 0;

void nodeSum(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    nodeSum(root->right);

    root->val = root->val + sum;

    sum = root->val;

    nodeSum(root->left);
}

TreeNode *bstToGst(TreeNode *root)
{
    nodeSum(root);

    return root;
}


int main()
{

    return 0;
}