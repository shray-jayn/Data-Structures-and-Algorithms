#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> nearestSmallestLeft(vector<ll> &arr, int n)
{
    vector<ll> ans;

    stack<pair<ll, ll>> st;

    for (int i = 0; i < n; i++)
    {
        if (st.size() == 0)
        {
            ans.push_back(-1);
        }

        if (st.size() > 0 and st.top().first < arr[i])
        {
            ans.push_back(st.top().second);
        }

        else if (st.size() > 0 and st.top().first >= arr[i])
        {
            while (st.size() > 0 and st.top().first >= arr[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top().second);
            }
        }

        st.push({arr[i], i});
    }

    return ans;
}

vector<ll> nearestSmallestRight(vector<ll> &arr, int n)
{
    vector<ll> ans;

    stack<pair<ll, ll>> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size() == 0)
        {
            ans.push_back(n);
        }

        if (st.size() > 0 and st.top().first < arr[i])
        {
            ans.push_back(st.top().second);
        }

        else if (st.size() > 0 and st.top().first >= arr[i])
        {
            while (st.size() > 0 and st.top().first >= arr[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                ans.push_back(n);
            }
            else
            {
                ans.push_back(st.top().second);
            }
        }

        st.push({arr[i], i});
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

ll getMaxArea(vector<ll> &arr, int n)
{
    // Your code here

    vector<ll> left = nearestSmallestLeft(arr, n);

    vector<ll> right = nearestSmallestRight(arr, n);

    vector<ll> width;
    for (int i = 0; i < n; i++)
    {
        ll a = right[i] - left[i] - 1;
        width.push_back(a);
    }

    vector<ll> area;

    ll maxArea = LONG_LONG_MIN;

    for (int i = 0; i < n; i++)
    {
        ll a = arr[i] * width[i];
        maxArea = max(maxArea, a);
        area.push_back(a);
    }

    return maxArea;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<ll>> rectangle;

    for (int i = 0; i < n; i++)
    {
        vector<ll> v;
        for (int j = 0; j < m; j++)
        {
            if (i == 0)
            {
                if (matrix[i][j] == '1')
                {
                    ll a = 1;
                    v.push_back(a);
                }
                else
                {
                    v.push_back(0);
                }
            }
            else
            {
                if (matrix[i][j] == '1')
                {
                    ll a = rectangle[i - 1][j] + 1;
                    v.push_back(a);
                }
                else if (matrix[i][j] == '0')
                {
                    v.push_back(0);
                }
            }
        }

        rectangle.push_back(v);
    }

    ll maxArea = LONG_LONG_MIN;

    for (int i = 0; i < rectangle.size(); i++)
    {
        int j = rectangle[i].size();

        ll area = getMaxArea(rectangle[i], j);

        maxArea = max(maxArea, area);
    }

    return maxArea;
}
int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                {'1', '0', '1', '1', '1'},
                                {'1', '1', '1', '1', '1'},
                                {'1', '0', '0', '1', '0'}};

    cout << maximalRectangle(matrix) << endl;
    return 0;
}
