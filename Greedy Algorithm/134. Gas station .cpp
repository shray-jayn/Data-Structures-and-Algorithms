#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();

    int total_fuel = 0, total_cost = 0;

    for (int i = 0; i < n; i++)
    {
        total_cost += cost[i];
        total_fuel += gas[i];
    }

    if (total_fuel < total_cost)
    {
        return -1;
    }

    int current = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        current += (gas[i] - cost[i]);

        if (current < 0)
        {
            current = 0;
            start = i + 1;
        }
    }

    return start;
}

int main()
{

    return 0;
}