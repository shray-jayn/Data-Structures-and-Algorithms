#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

long mod = 1e9 + 7;

void helper(Node *root1, Node *root2, long long &mul)
{
    if (!root1 || !root2)
        return;

    mul += ((root1->data) * (root2->data)) % mod;
    
    helper(root1->left, root2->right, mul);
    helper(root1->right, root2->left, mul);
}

long long imgMultiply(Node *root)
{
    long long mul = root->data * root->data;

    helper(root->left, root->right, mul);

    return mul % mod;
}


int main()
{

    return 0;
}