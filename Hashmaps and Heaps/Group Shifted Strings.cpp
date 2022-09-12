#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string getKey(string str)
{
    int n = str.size();
    string key = "";

    for (int i = 1; i < n; i++)
    {
        char curr = str[i];
        char prev = str[i - 1];

        int diff = curr - prev;

        if (diff < 0)
        {
            diff += 26;
        }

        key += diff + "#";
    }

    key += ".";

    return key;
}

vector<vector<string>> groupShiftedStrings(vector<string> strs)
{
    unordered_map<string, vector<string>> mp;

    for (auto str : strs)
    {
        string key = getKey(str);

        if (mp.find(key) == mp.end())
        {
            vector<string> arrList;
            arrList.push_back(str);

            mp[key] = arrList;
        }
        else
        {
            mp[key].push_back(str);
        }
    }

    vector<vector<string>> res;

    for (auto it : mp)
    {
        vector<string> val = it.second;
        res.push_back(val);
    }

    return res;
}

int main()
{

    return 0;
}