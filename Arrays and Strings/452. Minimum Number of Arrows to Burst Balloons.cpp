#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(), [](const std::vector<int> &a, const std::vector<int> &b)   // sort acc to end point
         { return a[1] < b[1]; });

        // sort
    int count_arrows = 1; // because atleast one arrow will be required to burst balloons
    int prev_end_point = points[0][1];

    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][0] > prev_end_point)  // curr start point is not less than prev end point so can't merge 
        {
            count_arrows++; // increment count

            // upadte end pointer
            prev_end_point = points[i][1];
        }
 
        else if(points[i][0] <=prev_end_point)  // merge ho rahe hai is conditon me 
        {
            continue;
        }
    }

    return count_arrows;
}

int main()
{

    return 0;
}