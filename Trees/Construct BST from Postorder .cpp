#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node
{
    int data;
    Node *left, *right;
};

Node *build(int post[], int size, int &i, int low, int high)
{
    if (size == 0 or post[i] <= low or post[i] >= high)
    {
        return nullptr;
    }

    Node *root = new Node;
    root->data = post[i--];
    root->right = build(post, size--, i, root->data, high);
    root->left = build(post, size--, i, low, root->data);

    return root;
}
Node *constructTree(int post[], int size)
{
    int i = size - 1;

    return build(post, size, i, INT_MIN, INT_MAX);
}

int main()
{

    return 0;
}