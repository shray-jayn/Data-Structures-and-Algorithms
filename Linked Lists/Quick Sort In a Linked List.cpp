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

int length(ListNode *node)
{
    if (node == NULL)
    {
        return 0;
    }

    ListNode *curr = node;
    int len = 0;

    while (curr != NULL)
    {
        curr = curr->next;
        len++;
    }

    return len;
}

vector<ListNode *> segregate(ListNode *head, int pivotIdx)
{
    ListNode *larger = new ListNode(-1);
    ListNode *smaller = new ListNode(-1);

    ListNode *curr = head, *sp = smaller, *lp = larger;

    ListNode *pivotNode = head;

    while (pivotIdx--)
    {
        pivotNode = pivotNode->next;
    }

    while (curr != NULL)
    {
        if (curr != pivotNode)
        {
            if (curr->val <= pivotNode->val)
            {
                sp->next = curr;
                sp = sp->next;
            }

            else
            {
                lp->next = curr;
                lp = lp->next;
            }
        }

        curr = curr->next;
    }

    sp->next = NULL;
    lp->next = NULL;
    pivotNode->next = NULL;

    return {smaller->next, pivotNode, larger->next};
}

vector<ListNode *> mergeSortedList(vector<ListNode *> leftSortedList, ListNode *pivotNode, vector<ListNode *> rightSortedList)
{
    ListNode *head = NULL, *tail = NULL;

    if (leftSortedList[0] != NULL and rightSortedList[0] != NULL)
    {
        leftSortedList[1]->next = pivotNode;
        pivotNode->next = rightSortedList[0];

        head = leftSortedList[0];
        tail = rightSortedList[1];
    }
    else if (leftSortedList[0] != NULL)
    {
    }
    else if (rightSortedList[0] != NULL)
    {
    }
    else 
    {

    }
}

vector<ListNode *> quickSort_(ListNode *head)
{

    if (head == NULL or head->next == NULL)
    {
        return {head, head};
    }

    int len = length(head);
    int pivotIdx = len / 2;

    vector<ListNode *> segregatedList = segregate(head, pivotIdx);

    vector<ListNode *> leftSortedList = quickSort_(segregatedList[0]);
    vector<ListNode *> rightSortedList = quickSort_(segregatedList[2]);

    return mergeSortedList(leftSortedList, segregatedList[1], rightSortedList);
}