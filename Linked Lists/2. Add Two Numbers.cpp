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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL or l2 == NULL)
    {
        return l1 == NULL ? l2 : l1;
    }

    ListNode *c1 = reverse(l1);
    ListNode *c2 = reverse(l2);

    ListNode *dummy = new ListNode(-1);
    ListNode *itr = dummy;

    int carry = 0;

    while (c1 != NULL or c2 != NULL or carry != 0)
    {
        int sum = carry + (c1 != NULL ? c1->val : 0) + (c2 != NULL ? c2->val : 0);

        int digit = sum % 10;
        carry = sum / 10;

        itr->next  = new ListNode(digit);
        itr = itr->next;

        if (c1 != NULL)
        {
            c1 = c1->next;
        }
        if (c2 != NULL)
        {
            c2 = c2->next;
        }
    }
    return reverse(dummy->next);
}