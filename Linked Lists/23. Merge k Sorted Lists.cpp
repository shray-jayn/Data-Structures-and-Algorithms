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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL or l2 == NULL)
    {
        return l1 != nullptr ? l1 : l2;
    }

    ListNode *c1 = l1;
    ListNode *c2 = l2;

    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;

    while (c1 != NULL and c2 != NULL)
    {
        if (c1->val < c2->val)
        {
            prev->next = c1;
            c1 = c1->next;
        }
        else
        {
            prev->next = c2;
            c2 = c2->next;
        }

        prev = prev->next;
    }

    prev->next = c1 != NULL ? c1 : c2;

    return dummy->next;
}

ListNode *merge(vector<ListNode *> &lists, int startIdx, int endIdx)
{

    if (startIdx > endIdx)
    {
        return NULL;
    }

    if (startIdx == endIdx)
    {
        return lists[startIdx];
    }

    int mid = (startIdx + endIdx) / 2;

    ListNode *l1 = merge(lists, startIdx, mid);
    ListNode *l2 = merge(lists, mid + 1, endIdx);

    return mergeTwoLists(l1, l2);
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
    {
        return NULL;
    }

    return merge(lists, 0, lists.size() - 1);
}

int main()
{

    return 0;
}