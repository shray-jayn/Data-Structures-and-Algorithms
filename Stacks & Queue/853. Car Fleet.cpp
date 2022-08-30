#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    int n = position.size();

    vector<pair<int, int>> array(n);

    for (int i = 0; i < n; i++)
    {
        array[i] = {position[i], speed[i]};
    }

    sort(array.begin(), array.end());

    vector<float> time(n);

    for (int i = 0; i < n; i++)
    {
        time[i] = (target - array[i].first) / (float)array[i].second;
    }

    stack<float> st;

    for (int i = 0; i < n; i++)
    {

        while (st.size() > 0 and st.top() <= time[i])
        {
            st.pop();
        }

        st.push(time[i]);
    }

    return st.size();
}

int main()
{
    int target = 10;

    vector<int> position = {0, 4, 2}, speed = {2, 1, 3};

    cout << carFleet(target, position, speed) << endl;

    return 0;
}