#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maxEqualSum(int n1, int n2, int n3, vector<int> &s1, vector<int> &s2, vector<int> &s3)
{
    int sum1 = 0, sum2 = 0, sum3 = 0;

    int top1 = 0, top2 = 0, top3 = 0;

    // get individual Sum 

    for (int i = 0; i < n1; i++)
    {
        sum1 = sum1 + s1[i];
    }

    for (int i = 0; i < n2; i++)
    {
        sum2 = sum2 + s2[i];
    }

    for (int i = 0; i < n3; i++)
    {
        sum3 = sum3 + s3[i];
    }

    int ans = 0;

    while (true)
    {
        if (top1 == n1 or top2 == n2 or top3 == n3) // no element are left
        {
            ans = 0;
            break;
        }
        if (sum1 == sum2 and sum2 == sum3) // all sum are equal
        {
            ans = sum1;
            break;
        }
        if (sum1 >= sum2 and sum1 >= sum3) // sum1 is greatest
        {
            sum1 -= s1[top1++];
        }
        else if (sum2 >= sum1 and sum2 >= sum3) // sum2 is greatest
        {
            sum2 -= s2[top2++];
        }
        else if (sum3 >= sum1 and sum3 >= sum2) // sum3 is greatest
        {
            sum3 -= s3[top3++];
        }
    }

    return ans;
}

int main()
{

    return 0;
}