#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *inorderSuccessor(Node *root, Node &target)
{
    Node *successor = NULL;

    while (root != NULL)
    {
        if (root->data <= target.data)
        {
            root = root->right;
        }

        else
        {
            successor = root;
            root = root->left;
        }
    }

    return successor;
}

int main()
{

    return 0;
}