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

// Approach 1 : Reverse PostOrder

TreeNode *prev = NULL;

void flatten(TreeNode *root)
{
    if (!root)
        return;

    flatten(root->right);
    flatten(root->left);

    root->right = prev;
    root->left = NULL;

    prev = root;
}

// Approach 2 : Morrris Traversal

void flatten(TreeNode *root)
{
    TreeNode *curr = root;

    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            TreeNode *prev = curr->left;

            while (prev->right)
            {
                prev = prev->right;
            }

            prev->right = curr->right;

            curr->right = curr->left;
        }

        curr = curr->right;
    }
}

void flatten(TreeNode *root)
{
    TreeNode *curr = root;
    while (curr)
    {
        if (curr->left)
        {
            TreeNode *prev = curr->left;

            while (prev->right != nullptr)
            {
                prev = prev->right;
            }

            prev->right = curr->right;
            curr->right = curr->left;
            
            curr->left = nullptr;
        }
        curr = curr->right;
    }
}

int main()
{

    return 0;
}