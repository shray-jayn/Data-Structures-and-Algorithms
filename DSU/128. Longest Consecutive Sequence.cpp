#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// we want to use disjoint set union for grouping the element which are adjacent

class DSU
{
private:
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n)
    {
        parent = vector<int>(n, 0);
        rank = vector<int>(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    void unian(int a, int b)
    {
        int x = find(a);
        int y = find(b);

        if (x == y)
        {
            return;
        }

        if (rank[x] > rank[y])
        {
            parent[y] = x;
        }
        else if (rank[x] < rank[y])
        {
            parent[x] = y;
        }
        else
        {
            parent[y] = x;
            rank[x] += 1;
        }
    }
};

int longestConsecutive(vector<int> &nums)
{

    int n = nums.size();

    DSU dsu(n);

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {                    ////for key value pair because in DSU we can use values
        mp[nums[i]] = i; //// only 0 to n-1
    }

    for (int i = 0; i < n; i++)
    {
        if (mp.find(nums[i] - 1) != mp.end())
        {                                            /// basically we want to add values in groups which
            dsu.unian(mp[nums[i]], mp[nums[i] - 1]); ///// are adjacent
        }

        else if (mp.find(nums[i] + 1) != mp.end())
        {
            dsu.unian(mp[nums[i]], mp[nums[i] + 1]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "parent" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << dsu.parent[i] << " ";
    }
    cout << endl;

    cout << "rank" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << dsu.rank[i] << " ";
    }
    cout << endl;

    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        m[dsu.find(i)]++; //  by this step we want to compute size of every group
    }

    int ans = 0;

    for (auto u : m)
    {
        ans = max(ans, u.second); //// u.second is a size of every group
    }

    return ans;
}

int main()
{
    vector<int> arr = {100, 4, 200, 1, 3, 2};

    cout << longestConsecutive(arr) << endl;

    return 0;
}