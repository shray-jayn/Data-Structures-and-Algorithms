#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

static bool comp(Job a, Job b)
{
    return a.profit > b.profit; // sorts according to the profit
}

vector<int> JobScheduling(Job arr[], int n)
{

    sort(arr, arr + n, comp);

    vector<bool> done(n, false);

    int day = 0;
    int profit = 0;

    for (int i = 0; i < n; i++)
    {
        int j = arr[i].dead - 1;

        // if deadline is greater than n

        j = min(n, j);

        for (int j; j >= 0; j--)
        {
            if (done[j] == false)
            {
                done[j] = true;

                day += 1;
                profit += arr[i].profit;

                break;
            }
        }
    }

    return {day, profit};
}

int main()
{

    return 0;
}