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

void Smallestkth(TreeNode *root, int &k, int &ans)
{
    if (root == NULL)
        return;

    Smallestkth(root->left, k, ans);

    k--;
    if (k == 0)
        ans = root->val;

    return Smallestkth(root->right, k, ans);
}
int kthSmallest(TreeNode *root, int k)
{
    int ans = -1;
    Smallestkth(root, k, ans);
    return ans;
}

int main()
{

    return 0;
}