#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class HitCounter
{
public:
    deque<int> dq;

    HitCounter()
    {
    }
    void hit(int timestamp)
    {
        dq.push_back(timestamp);

        int start = timestamp - 300 + 1;

        while (dq.front() < start)
        {
            dq.pop_front();
        }
    }
    int getHits(int timestamp)
    {
        int start = timestamp - 300 + 1;

        while (dq.front() < start)
        {
            dq.pop_front();
        }
    
        return dq.size();
    }
};

int main()
{
    return 0;
}