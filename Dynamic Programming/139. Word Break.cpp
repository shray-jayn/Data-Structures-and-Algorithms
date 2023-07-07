#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

unordered_map<string, bool> dp;

bool helper(string s, unordered_set<string> &wordDict)
{
    if (wordDict.find(s) != wordDict.end())
    {
        return true;
    }

    if (dp.find(s) != dp.end())
    {
        return dp[s];
    }

    for (int i = 0; i < s.size(); i++)
    {
        string s1 = s.substr(0, i + 1);
        string s2 = s.substr(i + 1);

        if (wordDict.find(s1) != wordDict.end())
        {
            bool ros = helper(s2, wordDict);

            if (ros == true)
            {
                return dp[s] = true;
            }
        }
    }

    return dp[s] = false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    int n = wordDict.size();

    unordered_set<string> st;

    for (int i = 0; i < n; i++)
    {
        st.insert(wordDict[i]);
    }

    return helper(s, st);
}

// unordered_map<string, bool> memo;

// bool wordBreakHelp(string word, unordered_map<string, bool> &dict)
// {
//     // if present in dict
//     if (dict.find(word) != dict.end())
//         return true;

//     // if present in memo, no need to call
//     if (memo.find(word) != memo.end())
//         return memo[word];

//     for (int i = 0; i < word.length(); i++)
//     {
//         string left = word.substr(0, i + 1); // always starts from beginning
//         string right = word.substr(i + 1);   // remaining string till the last letter;

//         if (dict.find(left) != dict.end())
//         {
//             bool ros = wordBreakHelp(right, dict); // rest of the string is recursed

//             if (ros == true)
//             {
//                 memo[word] = true; // entire word exists
//                 return true;
//             }
//         }
//     }

//     // if no prefix is found to be matching, word does not exist
//     memo[word] = false;
//     return false;
// }

// bool wordBreak(string s, vector<string> &wordDict)
// {
//     unordered_map<string, bool> dict;

//     for (string s : wordDict)
//         dict[s] = true;

//     return wordBreakHelp(s, dict);
// }

int main()
{
    string s = "leetcode";

    vector<string> words = {"leet", "code"};

    // cout << memo.size() << endl;

    cout << wordBreak(s, words) << endl;

    // cout << memo.size() << endl;

    return 0;
}