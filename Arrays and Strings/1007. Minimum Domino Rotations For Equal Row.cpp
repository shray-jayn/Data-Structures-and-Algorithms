#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
{
    int n = tops.size();

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;

    int num1 = tops[0];
    int num2 = bottoms[0];

    for (int i = 0; i < n; i++)
    {
        // for num-1
        // count-1 -> No. of swapping to make top array as Num-1;

        if (count1 != INT_MAX)
        {
            if (tops[i] == num1)
            {
                // do nothing
            }
            else if (bottoms[i] == num1)
            {
                count1++;
            }
            else
            {
                count1 = INT_MAX;
            }
        }

        // count-2 -> No. of swapping to make bottom array as Num-1;

        if (count2 != INT_MAX)
        {
            if (bottoms[i] == num1)
            {
                // do nothing
            }
            else if (tops[i] == num1)
            {
                count2++;
            }
            else
            {
                count2 = INT_MAX;
            }
        }

        // for num-2
        // count-3 -> No. of swapping to make top array as Num-2;

        if (count3 != INT_MAX)
        {
            if (bottoms[i] == num2)
            {
                // do nothing
            }
            else if (tops[i] == num2)
            {
                count3++;
            }
            else
            {
                count3 = INT_MAX;
            }
        }
        // count-4 -> No. of swapping to make bottom array as Num-2;

        if (count4 != INT_MAX)
        {
            if (tops[i] == num2)
            {
                // do nothing
            }
            else if (bottoms[i] == num2)
            {
                count4++;
            }
            else
            {
                count4 = INT_MAX;
            }
        }
    }

    int res = min({count1, count2, count3, count4});

    if (res == INT_MAX)
    {
        return -1;
    }

    return res;
}

int main()
{

    return 0;
}