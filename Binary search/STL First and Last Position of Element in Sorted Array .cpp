#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> v;


        // CHECK IF TARGET ELEMENT IS PRESENT   AND IF NOT RETRUN VECTOR WITH -1 -1 

        if (binary_search(nums.begin(), nums.end(), target))
        {
            
            int p = -1;

            // ITERATOR WHICH POINTS TO LOWERBOUND AND UPPERBOUND

            vector<int>::iterator low1, up1;


            // FOR FIRST APPERANE USE LOWERBOUND

            low1 = lower_bound(nums.begin(), nums.end(), target);
            int x = low1 - nums.begin();

            // CHECK IF INDEX IS HAVING TARGET OR NOT 

            if (nums[x] == target)
            {
                v.push_back(x);
            }
            else
            {
                v.push_back(p);
            }
            
            //FOR LAST APPEARENCE USE UPPER BOUND

            up1 = upper_bound(nums.begin(), nums.end(), target);
            int y = up1 - nums.begin() - 1;

            // CHECK IF INDEX IS HAVING TARGET OR NOT

            if (nums[y] == target)
            {
                v.push_back(y);
            }
            else
            {
                v.push_back(p);
            }

            return v;
        }


        // IF TARGET ELEMENT WAS NOT PRESENT 

        else
        {
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
    }

};