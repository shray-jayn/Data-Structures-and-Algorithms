#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string minWindow(string s, string t)
{
    int n = s.size();
    int m = t.size();

    string ans = "";

    unordered_map<char, int> map2;

    for (int i = 0; i < m; i++)
    {
        char ch = t[i];
        map2[ch]++;
    }

    int matchCount = 0;
    int desiredMatchCount = m;

    unordered_map<char, int> map1;

    int i = -1;
    int j = -1;

    while (true)
    {

        bool flag1 = false;
        bool flag2 = false;

        // acquire

        while (i < n - 1 and matchCount < desiredMatchCount)
        {
            i++;
            char ch = s[i];
            map1[ch]++;

            if (map1[ch] <= map2[ch])
            {
                matchCount++;
            }

            flag1 = true;
        }

        //  collect ans and relaease

        while (j < i and matchCount == desiredMatchCount)
        {
            string potentialAns = s.substr(j + 1, i + 1);

            if (potentialAns.size() < ans.size() or ans.size() == 0)
            {
                ans = potentialAns;
            }

            j++;

            char ch = s[j];

            if (map1[ch] == 1)
            {
                map1.erase(ch);
            }
            else
            {
                map1[ch]--;
            }

            if (map1[ch] < map2[ch])
            {
                matchCount--;
            }

            flag2 = true;
        }

        if (flag1 == false and flag2 == false)
        {
            break;
        }
    }

    return ans ;
}
int main()
{

    return 0;
}