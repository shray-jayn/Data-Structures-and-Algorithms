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

ListNode *segregate01(ListNode *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    ListNode *zero = new ListNode(-1);
    ListNode *one = new ListNode(-1);
    ListNode *two = new ListNode(-1);

    ListNode *itr0 = zero;
    ListNode *itr1 = one;
    ListNode *itr2 = two;

    ListNode *curr = head;

    while (curr != NULL)
    {
        if (curr->val == 0)
        {
            itr0->next = curr;
            itr0 = curr;
        }

        else if (curr->val == 1)
        {
            itr1->next = curr;
            itr1 = curr;
        }

        else if (curr->val == 2)
        {
            itr2->next = curr;
            itr2 = curr;
        }

        curr = curr->next;
    }

    itr0->next = one->next;
    itr1->next = two->next;
    itr2->next = NULL;

    return zero->next;
}

int main()
{

    return 0;
}