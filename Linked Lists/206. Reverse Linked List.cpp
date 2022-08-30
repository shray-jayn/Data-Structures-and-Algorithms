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

// Recursive
ListNode *reverseList(ListNode *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    ListNode *newHead = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}

// Iterative

ListNode *reverseList(ListNode *head)
{
    if (head == NULL or head->next == NULL) // 0 node or 1 node
    {
        return head;
    }

    ListNode *curr = head;
    ListNode *prev = NULL;
    ListNode *fwd = NULL;

    while (curr != NULL)
    {
        fwd = curr->next; // back up

        curr->next = prev; // attach link

        prev = curr; // move prev to current
        curr = fwd;  // move curr to fwd
    }

    return prev;
}

int main()
{

    return 0;
}