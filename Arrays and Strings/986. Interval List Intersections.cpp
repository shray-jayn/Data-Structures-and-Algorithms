#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
{
    vector<vector<int>> ans;

    int i = 0;
    int j = 0;

    // 0 is the starting point
    // 1 is the ending point

    while (i < firstList.size() && j < secondList.size())
    {
        int st = max(firstList[i][0], secondList[j][0]); // check which has maximum starting point because that will be the starting point of any intersection
        int et = min(firstList[i][1], secondList[j][1]);

        // for ending point it will be the minimum of both the ending point

        if (st <= et)
        {                            // case of interval intersection
            ans.push_back({st, et}); // push into ans
        }

        if (firstList[i][1] <= secondList[j][1])
        {
            // if ending point of firstList is smaller than secondlist ending point increment i
            i++;
        }
        else
        {
            j++; // otherwise increment j
        }
    }
    return ans;
}
