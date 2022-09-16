#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int furthestBuilding(vector<int> &heights, int bricks, int ladders)
{
    // step1->Use bricks initially and store the max bricks udes till now
    priority_queue<int> pq; // maxheap

    int i;

    int n = heights.size();

    for (i = 0; i < n - 1; i++)
    {
        int diff = heights[i + 1] - heights[i];

        if (diff <= 0)
        {
            continue;
        }

        else if (diff > 0)
        {
            if (diff <= bricks)
            {
                pq.push(diff); // this many numbers of bricks used in this jump
                bricks -= diff;
            }

            else
            {

                // we now have shortage of bricks -> go back and restore bricks and use ladder there

                if (ladders > 0 and pq.size() > 0 and pq.top() >= diff)
                {
                    bricks += pq.top();
                    pq.pop();
                    ladders -= 1;
                    pq.push(diff);
                    bricks -= diff;
                }
                
                else if (ladders > 0) // if no bricks(or this much required currently) used previously
                {                     // use ladders here
                    ladders--;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return i;
}

int main()
{

    return 0;
}