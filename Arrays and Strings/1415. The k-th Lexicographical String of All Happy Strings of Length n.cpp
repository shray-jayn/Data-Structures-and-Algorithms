#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Using Backtracking

vector<char> v = {'a', 'b', 'c'};

void helper(vector<string> &ans, string t, int n, char prev)
{
    if (n == 0)
    {
        ans.push_back(t);
        return;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (prev != v[i])
        {
            t.push_back(v[i]);
            helper(ans, t, n - 1, v[i]);

            t.pop_back(); // BACKTRACK
        }
    }
}

string getHappyString(int n, int k)
{

    vector<string> ans;
    string t = "";

    helper(ans, t, n, '#');

    if (ans.size() < k)
    {
        return "";
    }

    return ans[k - 1];
}

// O(n) Approach using Math

string getHappyString(int n, int k)
{
    int totalHappy = 3;

    for (int i = 1; i < n; i++) // add strings for each level
    {
        totalHappy = totalHappy * 2;
    }

    if (totalHappy < k)
    {
        return "";
    }

    int calls = 3;
    k--; // 0 based indexing

    int prevCall = -1;
    string ans = "";

    while (n--)
    {
        int singlePart = (totalHappy / calls);
        int newCall = (k / singlePart);

        if (newCall == 0)
        {
            if (prevCall == 0)
            {
                newCall = 1;
            }
            else
            {
                newCall = 0;
            }
        }
        else if (newCall == 1)
        {
            if (prevCall == -1 or prevCall == 2)
            {
                newCall = 1;
            }
            else
            {
                newCall = 2;
            }
        }
        else if (newCall == 2)
        {
            newCall = 2;
        }

        ans.push_back('a' + newCall);
        totalHappy = singlePart;
        prevCall = newCall;
        }

    return ans;
}

int main()
{

    return 0;
}