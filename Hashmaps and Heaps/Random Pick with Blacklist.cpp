#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    unordered_map<int, int> mp;
    unordered_set<int> st;
    int top;

    Solution(int n, vector<int> &blacklist)
    {
        int m = blacklist.size();
        top = n - m;

        for (int i = 0; i < m; i++)
        {
            st.insert(blacklist[i]);
        }

        int ele = n - 1; // last element

        for (int i = 0; i < blacklist.size(); i++)
        {
            if (blacklist[i] < top)
            {
                while (st.find(ele) != st.end())
                {
                    ele--;
                }

                mp[blacklist[i]] = ele;
                ele--;
            }
        }
    }

    int pick()
    {
        int randomIdx = rand() % top;

        if (mp.find(randomIdx) != mp.end())
        {
            return mp[randomIdx];
        }

        else
        {
            return randomIdx;
        }
    }
};

int main()
{

    return 0;
}