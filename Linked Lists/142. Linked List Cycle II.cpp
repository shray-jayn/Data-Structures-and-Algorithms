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

ListNode *detectCycle(ListNode *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) // cyclw is present
        {
            break;
        }
    }

    if (slow != fast)
    {
        return NULL;
    }

    slow = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main()
{

    return 0;
}