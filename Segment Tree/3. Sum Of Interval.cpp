#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class SegmentTree
{
public:
    vector<int> tree;
    vector<int> arr;

    SegmentTree(vector<int> ar)
    {
        arr = ar;
        tree.resize(4 * ar.size()); // set size of tree 4*N

        build(1, 0, arr.size() - 1);
    }

    void Update(int left, int right)
    {
    }

    int query(int pos, int val)
    {
    }

private:
    void build(int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;

        int left = node * 2;
        int right = node * 2 + 1;

        build(left, start, mid);
        build(right, mid + 1, end);

        tree[node] = tree[left] + tree[right];
    }

    void update_(int node, int start, int end, int pos, int val)
    {
        if (start == end) // Update the val
        {
            arr[start] = val;
            tree[node] = val;
        }

        int mid = (start + end) / 2;

        if (start <= pos and pos <= mid) // position in left sub tree
        {
            update_(node * 2, start, mid, pos, val);
        }

        else // position in right sub tree
        {
            update_(node * 2 + 1, mid + 1, end, pos, val);
        }

        tree[node] = tree[node * 2] + tree[node * 2 + 1]; // calculating sum again
    }

    int query(int node, int start, int end, int left, int right) // left - right (range of query) , start - end ( segment tree )
    {
        if (end < left or start > right) // out of range
        {
            return 0;
        }

        if (start == end) // leaf element
        {
            return tree[node];
        }

        else if (left <= start and right >= end) // exacty or partialy in range
        {
            return tree[node];
        }
        else
        {
            int mid = (left + right) / 2;

            int left = query(node * 2, start, mid, left, right);
            int right = query(node * 2 + 1, mid + 1, end, left, right);

            return left + right;
        }
    }
};

int main()
{

    return 0;
}