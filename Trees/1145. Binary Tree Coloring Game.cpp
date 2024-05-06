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

TreeNode *findNode(TreeNode *root, int &x)
{
    TreeNode *temp = NULL;
    if (root)
    {
        if (root->val == x)
            temp = root;
        else
        {
            temp = findNode(root->left, x);
            if (!temp)
                temp = findNode(root->right, x);
        }
    }
    return temp;
}

void countChildren(TreeNode *root, int &count)
{
    if (root)
    {
        count++;
        countChildren(root->left, count);
        countChildren(root->right, count);
    }
}

bool btreeGameWinningMove(TreeNode *root, int n, int x)
{
    int left = 0;
    int right = 0;
    int parent = 0;

    TreeNode *temp = findNode(root, x);

    countChildren(temp->left, left);
    countChildren(temp->right, right);

    int leftRightMax = max(left, right);

    if (temp->val != root->val)
    {   
        parent = n - (left + right + 1);
    }

    int maxChildren = max(leftRightMax, parent);

    return maxChildren > n - maxChildren;
}

int main()
{

    return 0;
}