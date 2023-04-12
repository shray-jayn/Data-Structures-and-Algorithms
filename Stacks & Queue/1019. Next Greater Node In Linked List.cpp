#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> nextGreaterNodeRight(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> ans;

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size() == 0)
        {
            ans.push_back(0);
        }

        if (st.size() > 0 and st.top() > arr[i])
        {
            ans.push_back(st.top());
        }
        else if (st.size() > 0 and st.top() <= arr[i])
        {
            while (st.size() > 0 and st.top() <= arr[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(st.top());
            }
        }

        st.push(arr[i]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> nextLargerNodes(ListNode *head)
{
    if (head == NULL)
    {
        return {0};
    }

    ListNode *node = head;
    vector<int> arr;

    while (node->next != NULL)
    {
        arr.push_back(node->val);
        node = node->next;
    }
    int n = arr.size();

    return nextGreaterNodeRight(arr, n);
}


