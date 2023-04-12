#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
string minWindow(string s, string t)
{
    unordered_map<char, int> mp;

    // calculate freq of each element of t
    
    for (int i = 0; i < t.size(); i++)
    {
        mp[t[i]]++;
    }

    int count = mp.size();  
    string ans;

    int mini = INT_MAX;

    int i = 0;
    int j = 0;

    while (j < s.size())
    {
        if (mp.find(s[j]) != mp.end())  // if element is present in T string reduce its freq
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
            {
                count--;
            }
        }

        while (count == 0)  // it meeans we have found all the elements of T string now we need to minimize the current lenght 
        {
            if (mini > j - i + 1)
            {
                mini = min(mini, j - i + 1);
                ans = s.substr(i, j - i + 1);
            }
            if (mp.find(s[i]) != mp.end())
            {
                mp[s[i]]++;
                if (mp[s[i]] == 1)
                {
                    count++;
                }
            }
            i++;
        }
        j++;
    }
    return ans;
}

int main()
{

    return 0;
}