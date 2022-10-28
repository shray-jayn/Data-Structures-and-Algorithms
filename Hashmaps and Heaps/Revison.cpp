#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Minimum window substring LC- hard

string minWindow(string s, string t)
{
    int n = s.size();
    int m = t.size();

    string ans = "";

    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;

    for (auto it : t) // generate frequce of t string
    {
        mp2[it]++;
    }

    int i = -1;
    int j = -1;

    int matchCount = 0;
    int desiredMatchCount = m;

    while (true)
    {
        bool flag1 = true;
        bool flag2 = true;

        // acquire

        while (matchCount != desiredMatchCount and i < n - 1)
        {
            i++;
            char ch = s[i];

            mp1[ch]++;

            if (mp2.find(ch) != mp2.end()) // check that element is requied in target or not ?
            {
                if (mp1[ch] <= mp2[ch])
                {
                    matchCount++;
                }
            }

            flag1 = true;
        }

        // collect ans and release

        while (j < i and matchCount == desiredMatchCount)
        {
            string potentialAns = s.substr(j + 1, i + 1);

            if (potentialAns.size() < ans.size() or ans.size() == 0)
            {
                ans = potentialAns;
            }

            j++;
            char ch = s[j];

            if (mp1[ch] == 1)
            {
                mp1.erase(ch);
            }
            else
            {
                mp1[ch]--;
            }

            if (mp1[ch] < mp2[ch])
            {
                matchCount--;
            }

            flag2 = true;
        }

        if (flag1 == false or flag2 == false)
        {
            break;
        }
    }
}

int main()
{

    return 0;
}