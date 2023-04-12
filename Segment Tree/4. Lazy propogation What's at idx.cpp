#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class SegmentTree
{
public:
    vector<int> lazy;
    vector<int> arr;

    SegmentTree(vector<int> ar)
    {
        arr = ar;
        lazy.resize(4 * ar.size()); // set size of tree 4*N

        build(1, 0, arr.size() - 1);
    }

    void Update(int left, int right)
    {
    }

    int query(int pos)
    {
    }

private:
    void build(int node, int start, int end)
    {
        if (start == end)
        {
            lazy[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;

        int left = node * 2;
        int right = node * 2 + 1;

        build(left, start, mid);
        build(right, mid + 1, end);

        lazy[node] = 0;
    }

    void update_(int node, int start, int end, int left, int right, int val)
    {

        if (end < left or start > right) // out of range
        {
            return;
        }

        if (start == end) // Update the val
        {
            lazy[node] += val; // add the value
        }

        else if (left <= start and right >= end) // lies compeletly in range
        {
            lazy[node] += val; // add that value to 0 and dont  pass to child
        }

        else
        {
            int mid = (start + end) / 2;

            update_(node * 2, start, mid, left, right, val);
            update_(node * 2 + 1, mid + 1, end, left, right, val);
        }
    }

    void propagate(int node, int start, int end)
    {

        if (start == end) // won't propogate for leaf nodes
        {
            return;
        }

        int left = node * 2;
        int right = node * 2 + 1;

        lazy[left] += lazy[node];
        lazy[right] += lazy[node];

        lazy[node] = 0;
    }

    int query(int node, int start, int end, int idx)
    {
        propagate(node, start, end);

        if (start == end)
        {
            return lazy[node];
        }

        else
        {
            int mid = (start + end) / 2;

            if (start <= idx and mid >= idx)
            {
                return query(node * 2, start, mid, idx); // left
            }

            else
            {
                return query(node * 2 + 1, mid + 1, end, idx); // right
            }
        }
    }
};

int main()
{

    return 0;
}