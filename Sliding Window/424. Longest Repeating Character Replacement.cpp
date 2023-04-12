#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int characterReplacement(string s, int k)
{
    int n = 0;
    int i = 0, j = 0;

    vector<int> mp(26, 0);

    int maxLen = 0;
    int maxCount = 0;

    while (j < n)
    {
        int idx = s[j] - 'A';
        mp[idx]++;

        maxCount = max(maxCount, mp[idx]);

        int winSize = (j - i + 1) - maxCount;

        while (winSize > k)
        {
            mp[s[i] - 'A']--;
            i++;
        }

        maxLen = max(maxLen, (j - i + 1));
    }

    return maxLen;
}

int main()
{

    string s = "AABABBA";
    int k = 1;

    cout << characterReplacement(s, k) << endl;

    return 0;
}