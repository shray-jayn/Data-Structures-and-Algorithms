#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> spiralOrder(vector<vector<int>> &m)
{
    int top = 0;
    int bottom = m.size() - 1;
    int left = 0;
    int right = m[0].size() - 1;

    vector<int> ans;

    while (top <= bottom and left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            // int v = m[top][i];
            ans.push_back(m[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            // int v = m[i][right];
            ans.push_back(m[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                // int v = m[bottom][i];
                ans.push_back(m[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                // int v = m[i][left];
                ans.push_back(m[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main()
{

    return 0;
}