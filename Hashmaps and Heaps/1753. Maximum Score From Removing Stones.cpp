#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maximumScore(int a, int b, int c)
{
    // max heap
    priority_queue<int, vector<int>> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);

    int score = 0;

    while (pq.size() > 1)
    {
        int curr1 = pq.top();
        pq.pop();
        int curr2 = pq.top();
        pq.pop();

        curr1--;
        curr2--;

        if (curr1 != 0)
        {
            pq.push(curr1);
        }
        if (curr2 != 0)
        {
            pq.push(curr2);
        }

        score++;
    }

    return score;
}

int main()
{

    return 0;
}