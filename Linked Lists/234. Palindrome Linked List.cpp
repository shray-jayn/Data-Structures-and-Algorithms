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

bool isPalindrome(ListNode *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    ListNode *mid = middleElement(head);

    ListNode *newHead = mid->next;

    mid->next = NULL;

    newHead = reverseList(newHead);

    ListNode *c1 = head;
    ListNode *c2 = newHead;

    bool result = true;

    while (c2 != NULL)
    {
        if (c1->val != c2->val)
        {
            result = false;
            break;
        }

        c1 = c1->next;
        c2 = c2->next;
    }

    return result;
}

int main()
{

    return 0;
}