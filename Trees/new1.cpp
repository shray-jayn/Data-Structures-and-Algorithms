#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int solve(vector<int> &nums)
{
    int n = nums.size();

    int hashsize = 1000000 + 1;

    vector<int> hash(hashsize, 0);

    for(int i =0 ;i< n;i++)
    {
        hash[nums[i]]++;
    }

    



}

int main()
{

    return 0;
}