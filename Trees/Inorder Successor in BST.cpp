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

Node *inOrderSuccessor(Node *root, Node *x)
{
    Node *successor = NULL;

    while (root != NULL)
    {
        if (x->data >= root->data)
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