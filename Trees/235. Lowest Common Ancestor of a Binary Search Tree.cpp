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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;
    if (root->val < p->val && root->val < q->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    if (root->val > p->val && root->val > q->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    else
        return root;
}
int main()
{

    return 0;
}