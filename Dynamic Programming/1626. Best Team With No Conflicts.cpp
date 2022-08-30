#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int bestTeamScore(vector<int> &scores, vector<int> &ages)
{
    int n = scores.size();

    vector<pair<int, int>> teamData(n); // age , score

    for (int i = 0; i < n; i++)
    {
        teamData[i] = {ages[i], scores[i]};
    }

    sort(teamData.begin(), teamData.end());

    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++)
    {
        dp[i] = teamData[i].second;
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int currAge = teamData[i].first;
        int currScore = teamData[i].second;

        for (int j = 0; j < i; j++)
        {
            int prevAge = teamData[j].first;
            int prevScore = teamData[j].second;

            if (currAge >= prevAge and currScore >= prevScore)
            {
                dp[i] = max(dp[i], currScore + dp[j]);
            }
        }

        ans = max(dp[i], ans);
    }

    return ans;
}

int main()
{

    return 0;
}