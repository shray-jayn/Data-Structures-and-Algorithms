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

// Iterative

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == NULL)
    {
        return new TreeNode(val);
    }

    TreeNode *cur = root;

    while (true)
    {
        if (cur->val <= val)
        {
            if (cur->right != NULL)
            {
                cur = cur->right;
            }

            else
            {
                cur->right = new TreeNode(val);
                break;
            }
        }

        else
        {
            if (cur->left != NULL)
            {
                cur = cur->left;
            }
            else
            {
                cur->left = new TreeNode(val);
                break;
            }
        }
    }

    return root;
}

// Recursive

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == NULL)
    {
        return new TreeNode(val);
    }

    if (root->val <= val)
    {
        root->right = insertIntoBST(root->right, val);
    }

    else
    {
        root->left = insertIntoBST(root->left, val);
    }

    return root;
}

int main()
{

    return 0;
}