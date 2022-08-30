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



TreeNode *solve(vector<int> &preorder, int pre_start, int pre_end, vector<int> &postorder, int post_start, int post_end, unordered_map<int, int> &mp)
{
    if (pre_start > pre_end or post_start > post_end)
        return NULL;

    int root_val = preorder[pre_start];

    TreeNode *root = new TreeNode(root_val);

    if (pre_start + 1 <= pre_end)
    {
        int pos = mp[preorder[pre_start + 1]];

        int num_left = pos - post_start + 1;

        root->left = solve(preorder, pre_start + 1, pre_start + num_left, postorder, post_start, pos, mp);

        root->right = solve(preorder, pre_start + 1 + num_left, pre_end, postorder, pos + 1, post_end - 1, mp);
    }

    return root;
}

TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    int n = preorder.size();

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[postorder[i]] = i;

    return solve(preorder, 0, n - 1, postorder, 0, n - 1, mp);
}

int main()
{

    return 0;
}