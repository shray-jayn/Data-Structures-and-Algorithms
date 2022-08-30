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

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int inStart, int inEnd, int preStart, int preEnd, map<int, int> inorderMap)
{
    if (inStart > inEnd or preStart > preEnd)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(preorder[preStart]);

    int inRoot = inorderMap[root->val];

    int numsLeft = inRoot - inStart;

    root->left = buildTree(preorder, inorder, inStart, inRoot - 1, preStart + 1, preStart + numsLeft, inorderMap);
    root->left = buildTree(preorder, inorder, inRoot + 1, inEnd, preStart + numsLeft + 1, preEnd, inorderMap);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.size() != inorder.size())
    {
        return NULL;
    }

    map<int, int> inorderMap;

    int n = inorder.size();

    for (int i = 0; i < n; i++)
    {
        inorderMap[inorder[i]] = i;
    }
}
int main()
{

    return 0;
}