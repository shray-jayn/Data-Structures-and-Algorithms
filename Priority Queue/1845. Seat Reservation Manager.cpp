#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class SeatManager
{
    unordered_set<int> st;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    SeatManager(int n)
    {
        for (int i = 0; i < n; i++)
        {
            pq.push(i);
        }
    }

    int reserve()
    {
        int val = pq.top();
        pq.pop();

        st.insert(val);

        return val;
    }

    void unreserve(int seatNumber)
    {
        st.erase(seatNumber);
    }
};

int main()
{

    return 0;
}