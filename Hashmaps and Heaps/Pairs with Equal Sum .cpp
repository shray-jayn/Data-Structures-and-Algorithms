#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool pairswithEqualSum(vector<int> arr)
{
    int n = arr.size();

    unordered_set<int> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];

            if (st.find(sum) != st.end())
            {
                return true;
            }
            else
            {
                st.insert(sum);
            }
        }
    }

    return false;
}

int main()
{

    return 0;
}