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

void inorder(TreeNode *root, vector<TreeNode *> &traversal)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, traversal);

    traversal.push_back(root);

    inorder(root->right, traversal);
}

void constBST(TreeNode *root, vector<TreeNode *> &traversal)
{
    
}

TreeNode *balanceBST(TreeNode *root)
{
    vector<TreeNode *> traversal;

    inorder(root, traversal);
}

int main()
{

    return 0;
}