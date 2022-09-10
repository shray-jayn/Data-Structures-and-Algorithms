#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int countEquivalentSubarrays(vector<int> arr)
{
    int n = arr.size();

    unordered_set<int> st;

    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    int k = st.size();

    unordered_map<int, int> mp;

    int ans = 0;
    int i = -1;
    int j = -1;

    while (true)
    {
        bool flag1 = false;
        bool flag2 = false;

        while (i < n - 1)
        {
            flag1 = true;

            i++;
            mp[arr[i]]++;

            if (mp.size() == k)
            {
                ans += n - i;
                break;
            }
        }

        while (j < i)
        {
            flag2 = true;

            j++;

            if (mp[arr[j]] == 1)
            {
                mp.erase(arr[i]);
            }
            else
            {
                mp[arr[i]]++;
            }
            if (mp.size() == k)
            {
                ans += n - i;
            }
            else if (mp.size() < k)
            {
                break;
            }
        }

        if (flag1 == false and flag2 == false)
        {
            break;
        }
    }

    return ans;
}

int main()
{

    return 0;
}