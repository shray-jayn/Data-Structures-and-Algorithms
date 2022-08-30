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

void solve(Node *root, Node *&prev, Node *&head, bool &f)
{
    if (root == NULL)
    {
        return;
    }

    solve(root->left, prev, head, f);

    if (f == 0)
    {
        f = 1;
        head = root;
        prev = root;
    }

    else
    {
        prev->right = root;
        prev->right->left = prev;
        prev = prev->right;
    }

    solve(root->right, prev, head, f);
}

Node *bToDLL(Node *root)
{
    Node *head = NULL, *prev = NULL;

    bool f = 0;

    solve(root, prev, head, f);

    return head;
}

int main()
{

    return 0;
}