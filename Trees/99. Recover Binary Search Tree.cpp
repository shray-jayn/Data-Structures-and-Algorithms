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

TreeNode *first;
TreeNode *middle;
TreeNode *last;
TreeNode *prev;

void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);

    if (prev != NULL and root->val < prev->val)
    {
        // if this is the forst violation mark them as "First" and "Middle"

        if (first == NULL)
        {
            first = prev;
            middle = root;
        }

        // if this is the second violation them mark this node as last node

        else
        {
            last = root;
        }
    }

    // update the prev node and chage it to current node ;

    prev = root;

    inorder(root->right);
}

void recoverTree(TreeNode *root)
{
    first = middle = last = NULL;

    TreeNode *prev = new TreeNode(INT_MIN);

    inorder(root);

    if (first != NULL and last != NULL)
    {
        swap(first->val, last->val);
    }

    else if (first != NULL and middle != NULL)
    {
        swap(first->val, middle->val);
    }

    
}

int main()
{

    return 0;
}