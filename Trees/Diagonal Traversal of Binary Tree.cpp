#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

//  A binary tree node

struct Node
{
    int data;
    Node *left, *right;
};

vector<int> diagonal(Node *root)
{
    queue<Node *> q;

    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    q.push(root);

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        while (temp)
        {
            if (temp->left)
            {
                q.push(temp->left);
            }

            ans.push_back(temp->data);
            temp = temp->right;
        }
    }

    return ans;
}

int main()
{

    return 0;
}