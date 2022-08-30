#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class TreeNode
{

public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
        {
            delete left;
        }

        if (right)
        {
            delete right;
        }
    }
};

TreeNode *mergeBST(TreeNode *root1, TreeNode *root2)
{
    
}