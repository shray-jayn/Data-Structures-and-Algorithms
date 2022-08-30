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

ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    ListNode *dummyEven = new ListNode(-1);
    ListNode *dummyOdd = new ListNode(-1);

    ListNode *evenTail = dummyEven;
    ListNode *OddTail = dummyOdd;

    ListNode *curr = head;

    while (curr != NULL)
    {
        if (curr->val % 2 == 0)
        {
            evenTail->next = curr;
            evenTail = evenTail->next;
        }
        else
        {
            OddTail->next = curr;
            OddTail = OddTail->next;
        }
        curr = curr->next;
    }

    evenTail->next = dummyOdd->next; // add all odd nodes after even nodes

    OddTail->next = NULL; // breaks link to even

    return evenTail->next;
}
int main()
{

    return 0;
}