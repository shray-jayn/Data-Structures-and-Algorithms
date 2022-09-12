#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int numRabbits(vector<int> &answers)
{
    int n = answers.size();

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[answers[i]]++;
    }

    int ans = 0;

    for (auto it : mp)
    {
        int key = it.first;
        int value = it.second;

        int groupSize = key + 1;
        int reportees = value;

        int totalGrps = (int)ceil((reportees * 1.0) / groupSize * 1.0);

        ans += totalGrps * groupSize;
    }

    return ans;
}

int main()
{

    return 0;
}