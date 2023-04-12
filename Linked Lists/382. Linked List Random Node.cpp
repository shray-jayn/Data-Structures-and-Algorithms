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

class Solution
{
public:
    map<int, ListNode *> mp;

    Solution(ListNode *head)
    {
        ListNode *temp = head;
        int i = 0;

        while (temp != NULL)
        {
            mp[i] = temp;
            i++;
            temp = temp->next;
        }
    }

    int getRandom()
    {
        int n = mp.size();
        return mp[rand() % n]->val;
    }
};

int main()
{

    return 0;
}