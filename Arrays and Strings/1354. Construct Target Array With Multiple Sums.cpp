#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isPossible(vector<int> &target)
{
    priority_queue<int> pq;

    long long sum = 0;

    for (auto i : target)
    {
        pq.push(i);
        sum += i;
    }

    while (pq.top() > 1)
    {
        int curr = pq.top();

        long long rest = sum - curr;

        if (curr < rest + 1 || rest == 0) // If largest element is less then the sum of rest or rest is 0 ie it can't be changed to 1
        {
            return false;
        }
        else
        {
            pq.pop();

            if (curr % rest == 0)
            {
                 // If remainder is zero then we replace that element with rest instead of 0 cause we don't want 0 in our initial array
                pq.push(rest);

                sum = rest + rest;
            }
            else
            {
                pq.push(curr % rest);
                sum = rest + curr % rest;
            }
        }
    }
    
    return true;
}

int main()
{

    return 0;
}