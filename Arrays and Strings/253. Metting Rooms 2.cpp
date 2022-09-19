#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Using Priority Queue

int meetingRooms(vector<vector<int>> &intervals)
{
    int n = intervals.size();

    sort(intervals.begin(), intervals.end());

    priority_queue<int, vector<int>, greater<int>> pq; // min Heap

    for (auto it : intervals)
    {
        if (pq.size() == 0) // no meeting is scheduled
        {
            // first meeting
            pq.push(it[1]);
        }

        else
        {
            if (pq.top() > it[0]) // create new room as old room is not free
            {
                pq.push(it[1]);
            }

            else // old meeting is finsished No new room created   | old room occupied
            {
                pq.pop();
                pq.push(it[1]);
            }
        }
    }

    return pq.size();
}

// Using Cronological Order

int meetingRooms(vector<vector<int>> &intervals)
{
    int n = intervals.size();

    vector<int> start(n, 0);
    vector<int> end(n, 0);

    for (int i = 0; i < n; i++)
    {
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0;
    int j = 0;
    int roomCount = 0;

    while (i < n)
    {
        if (start[i] < end[j]) // create new room
        {
            i++;
            roomCount++;
        }
        else // use old room as it is free now
        {
            i++;
            j++;
        }
    }

    return roomCount;
}

int main()
{

    return 0;
}