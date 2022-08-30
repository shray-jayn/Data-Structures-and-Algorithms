#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maxArea(vector<int> &height)
{
    int n = height.size();

    int start = 0;
    int end = n - 1;

    int leftMax = height[start];
    int rightMax = height[end];

    int ans = 0;

    while (start < end)
    {
        if (leftMax < rightMax)
        {
            cout << "yo ";
            int breath = (end - start);
            int lenght = leftMax;

            int area = breath * lenght;

            cout << area << " ";

            ans = max(ans, area);

            start++;
            leftMax = height[start];

            cout << ans << endl;
        }

        else if (leftMax >= rightMax)
        {
            cout << "hi ";
            int breath = (end - start);
            int length = rightMax;

            int area = breath * length;
            cout << area << " ";

            ans = max(ans, area);

            end--;
            rightMax = height[end];
            cout << ans << endl;
        }
    }

    return ans;
}

int main()
{
    vector<int> c = {1, 1};
    // vector<int> c = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(c) << endl;

    return 0;
}