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

ListNode *segregate(ListNode *head, int pivotIdx)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    int idx = 0;

    ListNode *pivot = head;

    while (pivot != NULL)
    {
        if (idx == pivotIdx)
        {
            break;
        }

        idx++;
        pivot = pivot->next;
    }

    ListNode *smaller = new ListNode(-1);
    ListNode *larger = new ListNode(-1);

    ListNode *sp = smaller;
    ListNode *lp = larger;

    ListNode *curr = head;

    idx = 0;

    ListNode *pivotPointer = NULL;

    while (curr != NULL)
    {
        if (idx == pivotIdx)
        {
            continue;
        }

        else if (curr->val <= pivot->val)
        {
            sp->next = curr;
            sp = sp->next;
        }
        else
        {
            lp->next = curr;
            lp = lp->next;
        }

        curr = curr->next;
        idx++;
    }

    sp->next = pivot;
    pivot->next = larger->next;
    lp->next = NULL;

    return smaller->next;
}
