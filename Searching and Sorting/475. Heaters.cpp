#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Pair
{
    int justSmaller = -1;
    int justLarger = -1;

    Pair()
    {
    }

    Pair(int js, int jl)
    { 
        this->justLarger = jl;
        this->justSmaller = js;
    }
};

Pair binarySearch(int val, vector<int> &arr)
{
    int n = arr.size();

    int low = 0;
    int high = n - 1;

    Pair p;

    p.justLarger = -1;
    p.justSmaller = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == val)
        {
            p.justSmaller = arr[mid];
            p.justLarger = arr[mid];
            break;
        }

        else if (arr[mid] < val)
        {
            p.justSmaller = arr[mid];
            low = mid + 1;
        }
        else
        {
            p.justLarger = arr[mid];
            high = mid - 1;
        }
    }

    return p;
}

int findRadius(vector<int> &houses, vector<int> &heaters)
{
    int n = houses.size();
    int m = heaters.size();

    sort(heaters.begin(), heaters.end());

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int hp = houses[i];

        Pair p = binarySearch(hp, heaters);

        int leftDist = (p.justSmaller == -1) ? INT_MAX : hp - p.justSmaller;
        int rightDist = (p.justLarger == -1) ? INT_MAX : p.justLarger - hp;

        int minDist = min(leftDist, rightDist);

        ans = max(ans, minDist);
    }

    return ans;
}

int main()
{

    return 0;
}