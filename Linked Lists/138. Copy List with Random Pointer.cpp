#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    unordered_map<Node *, Node *> mp;

    Node *curr = head;

    Node *newHead = new Node(-1);
    Node *prev = newHead;

    while (curr != NULL)
    {
        prev->next = new Node(curr->val);

        mp[curr] = prev->next;

        curr = curr->next;
        prev = prev->next;
    }

    newHead = newHead->next;

    Node *c1 = head;
    Node *c2 = newHead;

    while (c1->next != NULL)
    {
        if (c1->random != NULL)
        {
            c2->random = mp[c1->random];
        }

        else
        {
            c2->random = NULL;
        }

        c1 = c1->next;
        c2 = c2->next;
    }

    return newHead;
}

Node *copyList(Node *head)
{
    map<Node *, Node *> mp;

    int i = 0;
    Node *ptr = head;

    while (ptr)
    {
        mp[ptr] = new Node(ptr->val);
        ptr = ptr->next;
    }

    ptr = head;

    while (ptr)
    {
        mp[ptr]->next = mp[ptr->next];
        mp[ptr]->random = mp[ptr->random];
        ptr = ptr->next;
    }
    
    return mp[head];
}

int main()
{

    return 0;
}