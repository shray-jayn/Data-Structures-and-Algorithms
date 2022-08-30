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

ListNode *reverse(ListNode *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    ListNode *prev = NULL;
    ListNode *curr = head;

    while (curr != NULL)
    {
        ListNode *fwd = curr->next; // backup

        curr->next = prev; // new Link

        prev = curr; // move
        curr = fwd;
    }

    return prev;
}


ListNode *subtractTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l2 == NULL)
    {
        return l1;
    }

    if (l1 == NULL)
    {
        l2->val = -l2->val;

        return l2;
    }

    l1 = reverse(l1);
    l2 = reverse(l2);

    ListNode *dummy = new ListNode(-1);
    ListNode *itr = dummy;

    int borrow = 0;

    ListNode *c1 = l1;
    ListNode *c2 = l2;

    while (c1 != NULL)
    {
        int diff = borrow + c1->val - (c2 != NULL ? c2->val : 0);

        if (diff < 0)
        {
            borrow = -1;
            diff += 10;
        }

        else
        {
            borrow = 0;
        }

        itr->next = new ListNode(diff);
        itr = itr->next;

        c1 = c1->next;
        if (c2 != NULL)
            c2 = c2->next;
    }

    return reverse(dummy->next);
}
