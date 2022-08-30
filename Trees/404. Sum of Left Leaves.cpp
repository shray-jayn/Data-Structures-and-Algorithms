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

int sum = 0;

void solve(TreeNode *root, bool isLeft)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL and root->right == NULL and isLeft == true)
    {
        sum += root->val;
    }

    solve(root->left, true);
    solve(root->right, false);
}

int sumOfLeftLeaves(TreeNode *root)
{
    solve(root, false);
    return sum;
}
int main()
{

    return 0;
}