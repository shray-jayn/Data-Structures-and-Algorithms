#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class SmallestInfiniteSet
{
private:
    unordered_set<int> st;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    SmallestInfiniteSet()
    {
        for (int i = 1; i <= 1000; i++)
        {
            pq.push(i);
            st.insert(i);
        }
    }

    int popSmallest()
    {
        int val = pq.top();
        pq.pop();
        st.erase(val);

        return val;
    }

    void addBack(int num)
    {
        if (st.find(num) == st.end())
        {
            pq.push(num);
            st.insert(num);
        }
    }
};

int main()
{

    return 0;
}