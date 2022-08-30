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



TreeNode *deleteNode(TreeNode *root, int key)
{
    // base case
    if (!root)
    {
        return NULL;
    }
 

    // Search for key node 

    if (root->val > key)
    {
        // move left
        root->left = deleteNode(root->left, key);
    }
    else if (root->val < key)
    {
        // move right
        root->right = deleteNode(root->right, key);
    }

    else
    {
        // found KEy node 

        // 1) if it is leaf node then just remove

        if (!root->left && !root->right)
        {
            return NULL;
        }

        // if key node with one child

        else if (!root->left || !root->right)
        {
            if (!root->left)
            {
                return root->right;
            }
            else
            {
                return root->left;
            }
        }

        
      
             // if key node have 2 children
        else
        {
            // In this case we need to replace the node with it's inorder successor (The next node that comes in the inorder traversal) i.e; we need to replace it with either :
            // 1. The greatest value node in it's left subtree (or)
            // 2. The smallest value node in it's right subtree
            // and return the root


            TreeNode *temp = root->left;

            // search max right for maxi 

            while (temp->right)
            {
                temp = temp->right;
            }
            root->val = temp->val;

            root->left = deleteNode(root->left, temp->val);  // deleting the node which is replaced the key node from its orignal pos 

        }
    }
    return root;
}

