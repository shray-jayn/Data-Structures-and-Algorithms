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

ListNode *middleNode(ListNode *head) // Returns first middle
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != NULL and fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

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

ListNode *sortList(ListNode *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    ListNode *mid = middleNode(head);
    ListNode *newHead = mid->next;
    mid->next = NULL;

    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(newHead);

    return mergeTwoLists(l1, l2);
}

int main()
{

    return 0;
}