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

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    ListNode *dummy = new ListNode(-1);
    ListNode *itr = dummy;
    itr->next = head; // Potential first node ;

    ListNode *curr = head->next;

    while (curr != NULL)
    {
        bool flag = false;

        while (curr != NULL and itr->next->val == curr->val)
        {
            flag = true;
            curr = curr->next;
        }

        if (flag == true)
        {
            itr->next = curr;
        }
        else
        {
            itr = itr->next;
        }

        if (curr != NULL)
        {
            curr = curr->next;
        }
    }
    return dummy->next;
}
int main()
{

    return 0;
}