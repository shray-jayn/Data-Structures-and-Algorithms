#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isValid(string s)
{
    if (s[0] == '0')
        return false;
    int n = stoi(s);
    if (n <= 255)
        return true;
    return false;
}

void helper(int ind, int part, int n, string &s, string ans, vector<string> &res)
{
    if (ind == n and part == 4)
    {
        ans.pop_back(); // To remove that last dot "."
        res.push_back(ans);
    }
    if (ind == n || part == 4)
        return;

    helper(ind + 1, part + 1, n, s, ans + s[ind] + ".", res);
    if (ind + 2 <= n and isValid(s.substr(ind, 2)))
        helper(ind + 2, part + 1, n, s, ans + s.substr(ind, 2) + ".", res);
    if (ind + 3 <= n and isValid(s.substr(ind, 3)))
        helper(ind + 3, part + 1, n, s, ans + s.substr(ind, 3) + ".", res);
}
vector<string> restoreIpAddresses(string s)
{
    vector<string> res;
    int n = s.size();
    helper(0, 0, n, s, "", res);
    return res;
}

int main()
{

    return 0;
}