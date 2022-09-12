#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isArithmeticSequence(vector<int> arr)
{
    int n = arr.size();
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    unordered_set<int> st;

    for (int i = 0; i < n; i++)
    {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);

        st.insert(arr[i]);
    }

    int commonDiff = (maxVal - minVal) / (n - 1);

    for (int i = 0; i < n; i++)
    {
        int ai = minVal + i * commonDiff;

        if (st.find(ai) == st.end())
        {
            return false;
        }
    }

    return true;
}

int main()
{

    return 0;
}