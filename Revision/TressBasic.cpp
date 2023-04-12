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

Node *buildTree()
{
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *node = new Node(data);

    node->left = NULL;
    node->right = NULL;

    return node;
}

void inorderTraversal(Node *node)
{

    if (node == NULL)
    {
        return;
    }

    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl; // addng a new level

            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        // check for left node

        if (temp->left != NULL)
        {
            q.push(temp->left);
        }

        // check for right node

        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL and root->right == NULL)
    {
        return 1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int d1 = height(root->left) + height(root->right);
    int d2 = height(root->left);
    int d3 = height(root->right);

    return max(d1, max(d2, d3));
}

int replaceDecendantSum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL and root->right == NULL)
    {
        return root->data;
    }

    int leftSum = replaceDecendantSum(root->left);
    int rightSum = replaceDecendantSum(root->right);

    int temp = root->data;
    root->data = leftSum + rightSum;

    return root->data + temp;
}

// print at level k

void printLevelK(Node *root, int k)
{
    if (root == NULL)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
    }

    printLevelK(root->left, k - 1);
    printLevelK(root->right, k - 1);
}

// vertial order print

void helper(Node *root, int d, map<int, vector<int>> &mp)
{
    if (root == NULL)
    {
        return;
    }

    mp[d].push_back(root->data);

    helper(root->left, d - 1, mp);
    helper(root->right, d + 1, mp);
}

void verticalOrderPrint(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    map<int, vector<int>> mp;
    int d = 0;

    helper(root, d, mp);

    // Print the nodes

    for (auto it : mp)
    {
        int dist = it.first;
        vector<int> nodes = it.second;

        for (auto node : nodes)
        {
            cout << node << " ";
        }

        cout << endl;
    }

    return;
}

// height balanced tree

pair<int, bool> isHeightBalancedTree(Node *root)
{
    
}

// max subset sum

struct Pair
{
    int inc;
    int exc;
};

Pair maxSumSubset(Node* root)
{

}



//
int main()
{

    return 0;
}