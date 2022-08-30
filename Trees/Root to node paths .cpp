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



bool getPath(TreeNode *root, vector<int> &arr, int x)
{
    if (!root)
    {
        return false;
    }

    arr.push_back(root->val);

    if (root->val == x)
    {
        return true;
    }

    if (getPath(root->left, arr, x) or getPath(root->right, arr, x))
        return true;

    arr.pop_back(); // if both return false backtrack
    return false;
}

vector<int> binaryTreePaths(TreeNode *root, int x)
{
    vector<int> arr;

    if (root == NULL)
    {
        return arr;
    }

    getPath(root, arr, x);

    return arr;
}

int main()
{

    return 0;
}