#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findMinArrowShots(vector<vector<int>> &points)
{

    int n = points.size();

    vector<pair<int, int>> array; // <end , start>

    for (int i = 0; i < n; i++)
    {
        array.push_back({points[i][1], points[i][0]}); // push all points
    }

    sort(array.begin(), array.end());

    int count = n; // take size of array as total count

    int prev = 0;

    for (int i = 1; i < n; i++)
    {
        if (array[i].second <= array[prev].first)
        {
            count--; // if it is over lapping do count--;
        }
        else
        {
            prev = i;
        }
    }

    return count ;
}

int main()
{

    return 0;
}