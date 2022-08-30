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



TreeNode *builtHelper(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap)
{
    if (preStart > preEnd || inStart > inEnd)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(preorder[preStart]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;

    root->left = builtHelper(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);

    root->right = builtHelper(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

    return root;
}



// main function


TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (inorder.size() != preorder.size())
    {
        return NULL;
    }

    map<int, int> inMap;

    for (int i = 0; i < inorder.size(); i++)
    {
        inMap[inorder[i]] = i;
    }

    
    TreeNode *root = builtHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);

    return root;
}

int main()
{

    return 0;
}