#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int singleNumber(vector<int> &nums)
{
    int threeN = -1; // to set all bits as 1
    int threeNplus1 = 0;
    int threeNplus2 = 0;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int commonWith3N = (nums[i] & threeN);
        int commonWith3Nplus1 = (nums[i] & threeNplus1);
        int commonWith3Nplus2 = (nums[i] & threeNplus2);

        threeN = (threeN & (~commonWith3N));
        threeNplus1 = (threeNplus1 | commonWith3N);

        threeNplus1 = (threeNplus1 & (~commonWith3Nplus1));
        threeNplus2 = (threeNplus2 | commonWith3Nplus1);

        threeNplus2 = (threeNplus2 & (~commonWith3Nplus2));
        threeN = (threeN | commonWith3Nplus2);
    }

    return threeNplus1;
}

int main()
{
    return 0;
}