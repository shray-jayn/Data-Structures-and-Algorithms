#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Node
{
public:
    int val;
    Node *next;

    Node(int d)
    {
        this->val = d;
        this->next = NULL;
    }
};

// Reverse a Linked List Recursive

// Reverse a Linked List iterative

// Find middle element in linked list

Node *middleElement(Node *root)
{
    if (root == NULL or root->next == NULL)
    {
        return NULL;
    }

    Node *head = root;

    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL and fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Cycle in linked list

bool hasCycle(Node *root)
{
    if (root == NULL or root->next == NULL)
    {
        return NULL;
    }

    Node *head = root;

    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL and fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

// return head of cycle

Node *detectCycle(Node *root)
{
    if (root == NULL or root->next == NULL)
    {
        return NULL;
    }

    Node *head = root;

    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL and fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            break;
        }
    }

    if (slow != fast)
    {
        return NULL;
    }

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// Merge Two Sorted Lists

Node *mergeTwoLists(Node *l1, Node *l2)
{
    if (l1 == NULL or l2 == NULL)
    {
        return l1 != NULL ? l1 : l2;
    }

    Node *c1 = l1;
    Node *c2 = l2;

    Node *dummy = new Node(-1);
    Node *head = dummy;

    while (c1->next != NULL or c2->next != NULL)
    {
        if (c1->val < c2->val)
        {
            head->next = c1;
            c1 = c1->next;
        }
        else
        {
            head->next = c2;
            c2 = c2->next;
        }

        head = head->next;
    }

    head->next = c1 != NULL ? c1 : c2;

    return dummy->next;
}

