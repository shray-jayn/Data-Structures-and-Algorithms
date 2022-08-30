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


ListNode *helper(ListNode *head)
{
    if (head == NULL or head->next == NULL)
    {
        return NULL;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
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



ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{

    ListNode *tailA = headA;

    while (tailA->next != NULL)
        tailA = tailA->next;

    tailA->next = headB;

    ListNode *ans = helper(headA);

    tailA->next = NULL;

    return ans;
}


int main()
{

    return 0;
}