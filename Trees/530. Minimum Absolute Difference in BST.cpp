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

int minDiff = INT_MIN;

int prevVal = NULL;

void solve(TreeNode *root)
{
    if (!root)
        return;

    solve(root->left);

    if (prevVal != NULL)
    {
        minDiff = min(minDiff, abs(prevVal - root->val));
    }

    prevVal = root->val;

    solve(root->right);
}
int getMinimumDifference(TreeNode *root)
{
    solve(root);

    return minDiff;
}

int main()
{

    return 0;
}