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

ListNode *middleNode(ListNode *head) // Returns second middle
{
    ListNode *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next, fast = fast->next->next;
    }
    return slow;
}

