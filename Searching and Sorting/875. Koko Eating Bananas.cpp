#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isPossible(vector<int> &piles, int speed, int h)
{
    int time = 0;
    int n = piles.size();

    for (int i = 0; i < n; i++)
    {
        time += ceil((double)piles[i] / speed);
    }

    if (time <= h)
        return true;

    return false;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int n = piles.size();

    int maxSpeed = -1;

    for (int i = 0; i < n; i++)
    {
        maxSpeed = max(maxSpeed, piles[i]);
    }

    if (h == n)
    {
        return maxSpeed;
    }

    int low = 0;
    int high = maxSpeed;
    int minSpeed = INT_MAX;

    while (low <= high)
    {
        int speed = low + (high - low) / 2;

        if (isPossible(piles, speed, h) == true)
        {
            minSpeed = speed;
            high = speed - 1;
        }
        else
        {
            low = speed + 1;
        }
    }

    return minSpeed;
}

int main()
{

    return 0;
}