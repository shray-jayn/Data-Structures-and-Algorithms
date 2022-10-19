#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class MovingAverage
{
    queue<int> q;
    int len;
    long sum = 0;

    MovingAverage(int size)
    {
        len = size;
    }

    double next(int val)
    {
        sum += val;

        q.push(val);

        if (q.size() > len)
        {
            int temp = q.front();
            q.pop();

            sum -= temp;
        }

        double avg = (double)sum / q.size();

        return avg;
    }
};

int main()
{

    return 0;
}