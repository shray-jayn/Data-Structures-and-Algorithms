#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class NodeValue
{
public:
    int maxNode;
    int minNode;
    int size;

    NodeValue(int minNode, int maxNode, int size)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->size = size;
    }
};

NodeValue largestBstSubtreeHelper(Node *root)
{
    // if ROOT is NULL return a Dummy node

    if (root == NULL)
    {
        return NodeValue(INT_MAX, INT_MIN, 0);
    }

    // get values from the left and the right subtree

    auto left = largestBstSubtreeHelper(root->left);
    auto right = largestBstSubtreeHelper(root->right);

    // if CURR node is greater than  MAX in LEFT and smaller than MIN in RIGHT

    if (left.maxNode < root->data and root->data > right.minNode)
    {
        return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), 1 + left.size + right.size);
    }

    // else it is not a valid BST so RETURN [-inf , +inf ] so that parent cant be valid bst

    return NodeValue(INT_MIN, INT_MAX, max(left.size, right.size));
}

int largestBst(Node *root)
{

    return largestBstSubtreeHelper(root).size;
}

int main()
{

    return 0;
}