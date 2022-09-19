#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool meetingRooms(vector<vector<int>> &intervals)
{
  int n = intervals.size();
  sort(intervals.begin(), intervals.end());

  int endPoint = intervals[0][1];

  for (int i = 1; i < n; i++)
  {
    int startPoint = intervals[i][0];

    if (startPoint < endPoint) // it is an overlapping condition
    {
      return false;
    }
    else // No Overlapping
    {
      endPoint = intervals[i][1];
    }
  }
  return true;
}

int main()
{

  return 0;
}