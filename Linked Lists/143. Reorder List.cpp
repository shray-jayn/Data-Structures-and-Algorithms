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

ListNode *middleElement(ListNode *head)
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

ListNode *reverseList(ListNode *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    ListNode *newHead = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}

void reorderList(ListNode *head)
{
    ListNode *mid = middleElement(head);

    ListNode *newHead = mid->next;
    mid->next = NULL;

    newHead = reverseList(newHead);

    ListNode *c1 = head;
    ListNode *c2 = newHead;
    ListNode *f1 = NULL;
    ListNode *f2 = NULL;

    while (c2 != NULL)
    {
        f1 = c1->next; // Backup
        f2 = c2->next;

        c1->next = c2; // New Links
        c2->next = f1;

        c1 = f1; // Move pointers
        c2 = f2;
    }

    return ;
}

int main()
{

    return 0;
}