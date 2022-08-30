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

ListNode *reverseList(ListNode *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    ListNode *newHead = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}

void unfold(ListNode *head)
{
    if (head == NULL or head->next == NULL)
    {
        return;
    }

    ListNode *fh = head;       // first head
    ListNode *sh = head->next; // seconf head
    ListNode *fp = head;       // first previous
    ListNode *sp = head;       // second previous

    while (sp != NULL and sp->next != NULL)
    {
        ListNode *f = sh->next; // backup

        // Connect Links

        fp->next = f;
        sp->next = f->next;

        // move

        fp = fp->next;
        sp = sp->next;
    }

    fp->next = NULL;

    sh = reverseList(sh);

    fp->next = sh;

    return;
}

int main()
{

    return 0;
}