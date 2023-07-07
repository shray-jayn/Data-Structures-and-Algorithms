#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(string curr, string s, int i, vector<string> &ans)
{
    // if end of the string is reached
    if (i == s.length())
    {
        ans.push_back(curr); // push the current "curr" string to ans
        return;
    }

    if (isdigit(s[i]))
    { // case 1
        curr.push_back(s[i]);
        solve(curr, s, i + 1, ans);
    }
    else
    { // case 2
        // sub case 1, considering lower case
        string c1 = curr;
        c1.push_back(tolower(s[i]));
        solve(c1, s, i + 1, ans);

        // sub case 2, considering upper case
        string c2 = curr;
        c2.push_back(toupper(s[i]));
        solve(c2, s, i + 1, ans);
    }
}

vector<string> letterCasePermutation(string S)
{
    vector<string> ans;
    solve("", S, 0, ans);
    return ans;
}

int main()
{
    string s;
    cin >> s;

    vector<string> ans = letterCasePermutation(s);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}