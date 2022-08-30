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



// Reverse the linked list using ADD-FIRST method 

ListNode *tempHead = NULL;
ListNode *tempTail = NULL;

void addFirst(ListNode *node)
{
    if (tempHead == NULL)
    {
        tempHead = node;
        tempTail = node;
    }

    else
    {
        node->next = tempHead;
        tempHead = node;
    }
}

ListNode *reverseList(ListNode *head)
{
    ListNode *curr = head;

    while (curr != NULL)
    {
        ListNode *fwd = curr->next; // backup
        curr->next = NULL;

        addFirst(curr); // new Link

        curr = fwd; // move
    }

    return tempHead;
}