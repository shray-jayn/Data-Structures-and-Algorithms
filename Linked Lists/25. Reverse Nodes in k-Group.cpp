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

int lengthOfList(ListNode *head)
{
    ListNode *curr = head;
    int count = 0;

    while (curr->next != NULL)
    {
        count++;
        curr = curr->next;
    }

    return count;
}

ListNode *tempHead = NULL;
ListNode *tempTail = NULL;

void addFirstNode(ListNode *head)
{
    if (tempHead == NULL)
    {
        tempHead = head;
        tempTail = head;
    }

    else
    {
        head->next = tempHead;
        tempHead = head;
    }
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL or head->next == NULL or k == 0)
    {
        return head;
    }

    int length = lengthOfList(head);

    ListNode *curr = head;

    ListNode *orgHead = NULL;
    ListNode *orgTail = NULL;

    while (length >= k)
    {
        int tempK = k;

        while (tempK--)
        {
            ListNode *fwd = curr->next; // backup ;
            curr->next = NULL;

            addFirstNode(curr); // new link

            curr = fwd; // mov
        }

        if (orgHead == NULL)
        {
            orgHead = tempHead;
            orgTail = tempTail;
        }

        else
        {
            orgTail->next = tempHead;
            orgTail = tempTail;
        }

        tempHead = NULL;
        tempTail = NULL;

        length -= k;
    }

    orgTail->next = curr;

    return orgHead;
}
int main()
{

    return 0;
}