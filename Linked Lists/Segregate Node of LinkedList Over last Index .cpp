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

ListNode *getTailNode(ListNode *head)
{
    if (head == NULL)
    {
        return head;
    }

    ListNode *tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    return tail;
}

ListNode *segregateOverLastNode(ListNode *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    ListNode *tail = getTailNode(head);

    ListNode *smaller = new ListNode(-1);
    ListNode *ps = smaller;
    ListNode *larger = new ListNode(-1);
    ListNode *pl = larger;

    ListNode *curr = head;

    while (curr != NULL)
    {
        if (curr->val <= tail->val)
        {
            ps->next = curr;
            ps = ps->next;
        }
        else
        {
            pl->next = curr;
            pl = pl->next;
        }

        curr = curr->next;
    }

    ps->next = larger->next;
    pl->next = NULL;

    return ps;
}

int main()
{

    return 0;
}