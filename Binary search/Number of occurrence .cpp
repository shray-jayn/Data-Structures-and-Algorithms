#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
    int count(int arr[], int n, int x)
    {
        // code here\

        vector <int> nums , v ;
        for(int i = 0 ; i< n ; i++)
        {
            nums[i] = arr[i];
        }
        int target = x ;
        if (binary_search(nums.begin(), nums.end(), target))
        {

            int a= 0  , b = 0 ;

            // ITERATOR WHICH POINTS TO LOWERBOUND AND UPPERBOUND

            vector<int>::iterator low1, up1;

            // FOR FIRST APPERANE USE LOWERBOUND

            low1 = lower_bound(nums.begin(), nums.end(), target);
            int x = low1 - nums.begin();

            // CHECK IF INDEX IS HAVING TARGET OR NOT

            if (nums[x] == target)
            {
                v.push_back(x);
                a = x;
            }
            

            //FOR LAST APPEARENCE USE UPPER BOUND

            up1 = upper_bound(nums.begin(), nums.end(), target);
            int y = up1 - nums.begin() - 1;

            // CHECK IF INDEX IS HAVING TARGET OR NOT

            if (nums[y] == target)
            {
                v.push_back(y);
                b = y;
            }

            return b-a+1;
           
         
        }

        // IF TARGET ELEMENT WAS NOT PRESENT

        else
        {
           return 0;
        }
    }
    
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}