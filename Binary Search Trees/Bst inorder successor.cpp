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

TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
{
    TreeNode *successor = NULL;
    while (root != NULL)
    {
        if (p->val >= root->val)
        {
            root = root->right;
        }
        else
        {
            successor = root;
            root= root->left;
        }
    }
    return successor;
}

int main()
{

    return 0;
}