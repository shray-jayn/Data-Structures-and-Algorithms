#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node
{
    int data;
    Node *left, *right;
};

bool isLeaf(Node *root)
{
    if (root->left == NULL and root->right == NULL)
    {
        return true;
    }

    return false;
}

void addLeftBoundary(Node *root, vector<int> &res)
{
    auto curr = root->left;

    while (curr)
    {
        if (!isLeaf(curr)) // should not be the leaf node
        {
            res.push_back(curr->data);
        }

        if (curr->left)
        {
            curr = curr->left;
        }

        else
        {
            curr = curr->right;
        }
    }
}

void addRightBoundary(Node *root, vector<int> &res)
{
    auto curr = root->right;

    vector<int> temp;

    while (curr)
    {
        if (!isLeaf(curr)) // should not be the leaf node
        {
            temp.push_back(curr->data);
        }

        if (curr->right)
        {
            curr = curr->right;
        }

        else
        {
            curr = curr->left;
        }
    }

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        res.push_back(temp[i]);
    }
}

void addLeafBoundary(Node *root, vector<int> &res) // inorder traversal
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }

    if (root->left)
    {
        addLeafBoundary(root->left, res);
    }

    if (root->right)
    {
        addLeafBoundary(root->right, res);
    }
}

vector<int> boundary(Node *root)
{
    vector<int> res;

    if (root == NULL)
    {
        return res;
    }

    if (!isLeaf(root))
    {
        res.push_back(root->data);
    }

    addLeftBoundary(root, res);
    addLeafBoundary(root, res);
    addRightBoundary(root, res);

    return res;
}

int main()
{

    return 0;
}