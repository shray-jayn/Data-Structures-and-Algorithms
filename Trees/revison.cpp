#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// inorder traversal

vector<int> ans;

vector<int> inorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return ans;
    }

    inorderTraversal(root->left);
    ans.push_back(root->val);
    inorderTraversal(root->right);

    return ans;
}

// Level order traversal

vector<vector<int>> levelOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }

    vector<vector<int>> ans;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int len = q.size();

        vector<int> row;

        while (len--)
        {
            auto temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                break;
            }

            if (temp != NULL)
            {
                int valu = temp->val;
                row.push_back(valu);
            }

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }

        ans.push_back(row);
    }

    return ans;
}

// 1038. Binary Search Tree to Greater Sum Tree

int sum = 0;

void nodeSum(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    nodeSum(root->right);

    root->val = root->val + sum;

    sum = root->val;

    nodeSum(root->left);
}

TreeNode *bstToGst(TreeNode *root)
{
    nodeSum(root);

    return root;
}

// 116. Populating Next Right Pointers in Each Node

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root)
{

    if (root == NULL)
    {
        return NULL;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int len = q.size();

        while (len--)
        {
            Node *temp = q.front();

            if (len == 0)
            {
                temp->next = NULL;
            }
            else
            {
                Node *temp2 = q.front();
                temp->next = temp2;
            }

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }

    return root;
}

// 199. Binary Tree Right Side View

void dfs(TreeNode *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (ans.size() < level)
    {
        ans.push_back(root->val);
    }

    dfs(root->right, ans, level + 1);

    dfs(root->left, ans, level + 1);
}

vector<int> rightSideView(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }
    vector<int> rightView;
    dfs(root, rightView, 1);
    return rightView;
}

// vertical order traversal

void dfs(TreeNode *root, int d, map<int, vector<int>> &mp)
{
    if (root == NULL)
    {
        return;
    }

    mp[d].push_back(root->val);

    dfs(root->left, d + 1, mp);
    dfs(root->right, d - 1, mp);
}

vector<vector<int>> verticalOrderTraversal(TreeNode *root)
{
    map<int, vector<int>> mp;
    dfs(root, 0, mp);

    vector<vector<int>> result;

    for (auto it : mp)
    {
        int key = it.first;
        vector<int> val = it.second;

        vector<int> row;

        for (auto k : val)
        {
            row.push_back(k);
        }

        result.push_back(row);
    }
    return result;
}

// Boundary Traversal of binary tree

bool isLeafNode(TreeNode *root)
{
    if (root->left == NULL and root->right == NULL)
    {
        return true;
    }
    return false;
}

void leftBoundary(TreeNode *root, vector<int> &res)
{
    TreeNode *curr = root;

    while (curr != NULL)
    {
        if (isLeafNode(curr) != true)
        {
            res.push_back(curr->val);
        }

        if (curr->left != NULL)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}
void rightBoundary(TreeNode *root, vector<int> &res)
{
    TreeNode *curr = root;
    vector<int> temp;

    while (curr != NULL)
    {
        if (isLeafNode(curr) != true)
        {
            temp.push_back(curr->val);
        }

        if (curr->right != NULL)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }

    // reverse the order ;
    reverse(temp.begin(), temp.begin());

    for (int i = 0; i < temp.size(); i++)
    {
        res.push_back(temp[i]);
    }
}
void leafNodes(TreeNode *root, vector<int> &res)
{
    if (root == NULL)
    {
        return;
    }

    leafNodes(root->left, res);

    if (isLeafNode(root) == true)
    {
        res.push_back(root->val);
    }

    leafNodes(root->left, res);
}

vector<int> boundary(TreeNode *root)
{
    vector<int> res;

    if (root == NULL)
    {
        return res;
    }

    leftBoundary(root->left, res);
    leafNodes(root, res);
    rightBoundary(root->right, res);

    return res;
}

// Diagonal Traversal of Binary Tree

vector<int> diagonal(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }

    queue<TreeNode *> q;
    q.push(root);

    vector<int> ans;

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        while (temp != NULL)
        {
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            ans.push_back(temp->val);
            temp = temp->right;
        }
    }

    return ans;
}

// 1145. Binary Tree Coloring Game
bool btreeGameWinningMove(TreeNode *root, int n, int x)
{
}

// Lowest Common Ancestor in a Binary Tree

TreeNode *lca(TreeNode *root, int n1, int n2)
{
}

// 235. Lowest Common Ancestor of a Binary Search Tree

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
}