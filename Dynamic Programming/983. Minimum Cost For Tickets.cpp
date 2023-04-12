#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int solve(vector<int> &days, vector<int> &costs, int i, int finalDays)
{

    if (i == days.size()) // base condition
    {
        return 0;
    }

    if (days[i] <= finalDays) // already ticket purchased for that day
    {
        return solve(days, costs, i + 1, finalDays);
    }

    int one_Day = costs[0] + solve(days, costs, i + 1, days[i] + 1);
    int seven_Day = costs[1] + solve(days, costs, i + 1, days[i] + 6);
    int thirty_Day = costs[2] + solve(days, costs, i + 1, days[i] + 29);

    return min(one_Day, min(seven_Day, thirty_Day));
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    return solve(days, costs, 0, 0);
}

int main()
{

    return 0;
}