#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> nearestSmallerInLeft(vector<int> &heights)
{
    int n = heights.size();

    stack<pair<int, int>> st; // <value , index>
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        if (st.size() == 0)
        {
            result.push_back(-1);
        }

        else if (st.size() > 0 and st.top().first <= heights[i])
        {
            result.push_back(st.top().second);
        }

        else if (st.size() > 0 and st.top().first > heights[i])
        {
            while (st.size() > 0 and st.top().first > heights[i])
            {
                st.pop();
            }

            if (st.size() == 0)
            {
                result.push_back(-1);
            }

            else
            {
                result.push_back(st.top().second);
            }
        }

        st.push({heights[i], i});
    }

    return result;
}

vector<int> nearestSmallerInRight(vector<int> &heights)
{
    int n = heights.size();

    stack<pair<int, int>> st; // <value , index>

    vector<int> result;

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size() == 0)
        {
            result.push_back(n);
        }

        else if (st.size() > 0 and st.top().first <= heights[i])
        {
            result.push_back(st.top().second);
        }

        else if (st.size() > 0 and st.top().first > heights[i])
        {
            while (st.size() > 0 and st.top().first > heights[i])
            {
                st.pop();
            }

            if (st.size() == 0)
            {
                result.push_back(n);
            }

            else
            {
                result.push_back(st.top().second);
            }
        }

        st.push({heights[i], i});
    }

    reverse(result.begin(), result.end());

    return result;
}

int largestRectangleArea(vector<int> &arr)
{
    int n = arr.size();

    vector<int> left = nearestSmallerInLeft(arr);

    vector<int> right = nearestSmallerInRight(arr);

    vector<int> width;
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


