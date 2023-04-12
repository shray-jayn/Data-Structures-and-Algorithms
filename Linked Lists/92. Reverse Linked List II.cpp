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

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (head == NULL)
    {
        return NULL;
    }

    ListNode *prev = NULL;
    ListNode *curr = head;

    while (left > 1) // when left = 1 we have reached start of range
    {
        prev = curr;
        curr = curr->next;
        left--;
        right--;
    }

    ListNode *connection = prev;
    ListNode *tail = curr;

    while (right > 0)
    {
        // reverse linked list

        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        right--;
    }

    if (connection != NULL)
    {
        connection->next = prev;
    }
    else
    {
        head = prev;
    }
    tail->next = curr; 

    return head;
}
