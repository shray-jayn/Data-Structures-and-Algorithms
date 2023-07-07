#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<string> res;

bool isValid(string s)
{
    int val = stoi(s);

    if (val > 255)
    {
        return false;
    }
    if (s.size() > 1 and s[0] == '0')
    {
        return false;
    }

    return true;
}

void helper(string currStr, string s, int idx, int dots)
{
    if (dots == 4 and idx == s.size())
    {
        currStr.pop_back();
        res.push_back(currStr);

        cout << currStr << endl;

        return;
    }

    if (dots == 4 or idx == s.size())
    {
        return;
    }

    helper(currStr + s[idx] + '.', s, idx + 1, dots + 1);

    if (isValid(s.substr(idx, 2)) and idx + 1 < s.size())
    {
        helper(currStr + s.substr(idx, 2) + '.', s, idx + 2, dots + 1);
    }

    if (isValid(s.substr(idx, 3)) and idx + 1 < s.size())
    {
        helper(currStr + s.substr(idx, 3) + '.', s, idx + 3, dots + 1);
    }
}

vector<string> restoreIpAddresses(string s)
{
    int n = s.size();

    helper("", s, 0, 0);

    return res;
}

int main()
{
    string s;
    cin >> s;

    vector<string> ans = restoreIpAddresses(s);

    return 0;
}