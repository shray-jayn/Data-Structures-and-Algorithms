#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *midNode(ListNode *head)
{

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

TreeNode *sortedListToBST(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *mid = midNode(head);
}

TreeNode *helper(ListNode *start, ListNode *end)
{
    if (start == end) // only 1 element 
    {

    }
}

int main()
{

    return 0;
}