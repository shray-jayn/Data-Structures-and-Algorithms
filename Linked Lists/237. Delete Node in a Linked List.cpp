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

ListNode *midNode(ListNode *node)
{
    if (node == NULL or node->next == NULL)
    {
        return node;
    }

    ListNode *slow = node;
    ListNode *fast = node;

    while(fast->next->next != NULL and fast->next != NULL)
    {
        
    }
}

void deleteNode(ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}

int main()
{

    return 0;
}