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

// Boundary traversal

bool isLeafNode(Node *node)
{
    if (node->left == NULL and node->right == NULL)
    {
        return true;
    }

    return false;
}

void addLeftBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->left;

    while (curr != NULL)
    {
        if (!isLeafNode(curr))
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
    vector<int> temp;

    Node *curr = root->right;

    while (curr != NULL)
    {
        if (!isLeafNode(curr))
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

void addLeafBoundary(Node *root, vector<int> &res)
{
    if (isLeafNode(root))
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

vector<int> printBoundary(Node *root)
{
    if (root == NULL)
    {
        return {};
    }

    vector<int> res;

    addLeftBoundary(root, res);
    addRightBoundary(root, res);
    addLeafBoundary(root, res);

    return res;
}

// Lowest common ansestor

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root == NULL or root == p or root == q) // return node if we find it ,, else return NULL if we don't find it
    {
        return root;
    }

    Node *left = lowestCommonAncestor(root->left, p, q);
    Node *right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL) // left undesired and right desired
    {
        return right;
    }

    else if (right == NULL) // left desired and right undesired
    {
        return left;
    }

    else if (left and right) // left desired and right desired
    {
        return root;
    }
}

// Lowest common ansestor (BST)

Node *lowestCommonAncestorBST(Node *root, Node *p, Node *q)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data > p->data and root->data > q->data)
    {
        lowestCommonAncestorBST(root->left, p, q);
    }

    if (root->data < p->data and root->data < q->data)
    {
        lowestCommonAncestorBST(root->right, p, q);
    }

    else
    {
        return root;
    }
}

// Binary tree to doubly linked list

// The left = previous
// right = next

void helper(Node *root, Node *head, Node *prev, bool isFirst)
{
    if (root == NULL)
    {
        return;
    }

    helper(root->left, head, prev, isFirst);

    if (isFirst == 0) // it is the first node
    {
        isFirst = 1;
        head = root;
        prev = root;
    }

    else // it is not the first node
    {
        prev->right = root;       //  take the prev element -> next = cur
        prev->right->left = prev; // add a pointer to previous node from current node
        prev = prev->right;       // mark as curr element
    }

    helper(root->right, head, prev, isFirst);
}

Node *BtToDll(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    Node *head = NULL;
    Node *prev = NULL;

    bool isFirst = 0;
}

// Construct Binary tree from inorder and preorder Traversal

Node *buildTreeHelper(int preStart, int preEnd, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder)
{

    Node *root = new Node(preorder[preStart]);

    Node *leftPart = buildTreeHelper(0, 0, 0, 0, preorder, inorder);
    Node *rightPart = buildTreeHelper(0, 0, 0, 0, preorder, inorder);
}

Node *constructFromPreIn(vector<int> &preorder, vector<int> &inorder)
{
    int n = preorder.size();

    int preStart = 0;
    int preEnd = n - 1;
    int inStart = 0;
    int inEnd = n - 1;

    Node *root = buildTreeHelper(preStart, preEnd, inStart, inEnd, preorder, inorder);

    return root;
}

// Print all nodes at distance k

void generateParent(Node *root, unordered_map<Node *, Node *> &mp)
{
    // use bfs

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *currNode = q.front();
        q.pop();

        if (currNode->left)
        {
            mp[currNode->left] = currNode;
            q.push(currNode->left);
        }

        if (currNode->right)
        {
            mp[currNode->right] = currNode;
            q.push(currNode->right);
        }
    }

    return;
}

vector<int> distanceK(Node *root, Node *target, int k)
{
    unordered_map<Node *, Node *> mp;

    generateParent(root, mp);

    unordered_map<Node *, bool> isVisited;

    // use multi source bfs

    vector<int> res;

    queue<Node *> q;

    q.push(target);
    isVisited[target] = true;

    int currLevel = 0;

    while (!q.empty())
    {
        int sze = q.size();

        if (currLevel == k)
        {
            break;
        }

        while (sze--)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left and isVisited[temp->left] != true)
            {
                isVisited[temp->left] = true;
                q.push(temp->left);
            }

            if (temp->right and isVisited[temp->right] != true)
            {
                isVisited[temp->right] = true;
                q.push(temp->right);
            }

            if (mp[temp] and isVisited[mp[temp]] != true)
            {
                isVisited[mp[temp]] = true;
                q.push(mp[temp]);
            }
        }

        currLevel++;
    }

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        res.push_back(temp->data);
    }

    return res;
}

// sum of left leaf

int sum = 0;

void solve(Node *root, bool isLeftNode)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL and root->right and isLeftNode == true)
    {
        sum += root->data;
        return;
    }

    solve(root->left, 1);
    solve(root->right, 0);
}

// Maximum width of a binary tree

int maxWidth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int res = 1;

    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        int len = q.size();

        int start = q.front().second;
        int end = q.back().second;

        int dist = end - start + 1;

        res = max(res, dist);

        while (len--)
        {
            auto temp = q.front();
            q.pop();

            Node *currNode = temp.first;
            int idx = temp.second;

            if (currNode->left)
            {
                int val = 2 * idx + 1;
                q.push({currNode->left, val});
            }

            if (currNode->right)
            {
                int val = 2 * idx + 2;
                q.push({currNode->right, val});
            }
        }
    }

    return res;
}

//  Print root to node paths

bool getPaths(Node *root, vector<int> path, int target)
{
    if (root == NULL)
    {
        return false;
    }

}

// Write code for printing binary tree paths?

