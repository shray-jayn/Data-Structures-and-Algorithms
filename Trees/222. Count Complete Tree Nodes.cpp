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

int findHeightLeft(TreeNode *root)
{
    int height = 0;

    while (root)
    {
        root = root->left;
        height++;
    }

    return height;
}

int findHeightRight(TreeNode *root)
{
    int height = 0;

    while (root)
    {
        root = root->right;
        height++;
    }

    return height;
}

int countNodes(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);

    if (lh == rh)
    {
        return (1 << lh) - 1; // 2^(n-1) -1 ;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{

    return 0;
}