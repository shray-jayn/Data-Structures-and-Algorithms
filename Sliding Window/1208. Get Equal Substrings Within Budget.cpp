#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int equalSubstring(string s, string t, int maxCost)
{
    int n = s.size();
    int i = 0, j = 0;
    int ans = 0;
    int cost = 0;

    while (j < n)
    {
        cost += abs(s[j] - t[j]);

        if (cost <= maxCost)
        {
            int len = j - i + 1;
            ans = max(ans, len);
            j++;
        }
        else if (cost > maxCost)
        {
            while (cost > maxCost)
            {
                cost -= abs(s[i] - t[i]);
                i++;
            }
            
            int len = j - i + 1;
            ans = max(ans, len);
            j++;
        }
    }
    return ans;
}

int main()
{

    return 0;
}