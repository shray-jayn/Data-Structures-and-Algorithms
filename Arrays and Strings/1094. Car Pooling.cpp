#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool carPooling(vector<vector<int>> &trips, int capacity)
{
    vector<int> lines(1000, 0);

    // now calculate at every point how many passenger can sit

    for (int i = 0; i < trips.size(); i++)
    {
        lines[trips[i][1]] += trips[i][0]; // starting position +num_passenger

        lines[trips[i][2]] -= trips[i][0]; // ending position -num_passenger
        
    }

    for (int i = 1; i < lines.size(); i++)
    {
        lines[i] += lines[i - 1]; // calculate cumulative sum at every index

        if (lines[i] > capacity)
        {
            return false;
        }
    }

    return true;
}

int main()
{

    return 0;
}