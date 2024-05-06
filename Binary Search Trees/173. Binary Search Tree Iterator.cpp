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



class BSTIterator
{
public:
    stack<TreeNode *> myStack;

    void pushAll(TreeNode *node)
    {
        for (; node != NULL; myStack.push(node), node = node->left) // push all the lefts into the stack of a node
            ;
    }

    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

    bool hasNext()
    {
        // if stack is not empty I do have elements  and if it is empty I don't have elements
        return !myStack.empty();
    }
};

int main()
{

    return 0;
}