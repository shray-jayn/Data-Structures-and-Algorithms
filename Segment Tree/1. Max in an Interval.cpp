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

        build(1, 0, arr.size() - 1); // node of segment tree is 1 based indexed
    }

private:
    void build(int node, int start, int end)
    {
        if (start == end) // this is the leaf node
        {
            tree[node] = arr[start]; // add value in segment tree from array
            return;
        }

        int mid = (start + end) / 2;

        int left = node * 2;
        int right = node * 2 + 1;

        build(left, start, mid);    // builds the left subtree
        build(right, mid + 1, end); // builds the right subtree

        tree[node] = max(tree[left], tree[right]); // stroes the max value from left and right subtree
    }

    int query(int node, int start, int end, int left, int right) // left - right (range of query) , start - end ( segment tree )
    {
        if (end < left or right < start) // out of range  {rahe thi [4-7] or mera start-emd hai [0-3]}
        {
            return INT_MIN; // returns - infinity
        }

        if (start == end) // leaf element
        {
            return tree[node]; // returns leaf node
        }

        else if ((left == start and end == right) or (left <= start and end <= right)) // exacty or partialy in range
        {
            return tree[node];
        }
        else
        {
            int mid = (left + right) / 2;

            int left = query(node * 2, start, mid, left, right);
            int right = query(node * 2 + 1, mid + 1, end, left, right);

            return max(left, right);
        }
    }

public:
    int query(int left, int right)
    {
        return query(1, 0, arr.size() - 1, left, right);
    }
};

int main()
{

    return 0;
}