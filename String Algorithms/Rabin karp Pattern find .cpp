#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void RabinKarp(string s1, string s2)
{
    vector<long> prefixHash(s1.size());
    vector<long> powArr(s1.size());

    long mod = 1000000007;

    long p = 31;
    long pow = 31;
    long desiredValue = s2[0] - 'a' + 1;


    //  calculte hash valfe of string which we hve to find 

    for (int i = 1; i < s2.length(); i++)
    {
        desiredValue = (desiredValue + (s2[i] - 'a' + 1) * pow) % mod;

        pow = (pow * p) % mod;
    }

    prefixHash[0] = s1[0] - 'a' + 1;
    powArr[0] = 1;

    long pow = 31;

    //  calculte hash valfe of string in which we hve to find the other string


    for (int i = 0; i < s1.size(); i++)
    {
        prefixHash[i] = (prefixHash[i - 1] + (s1[i] - 'a' + 1) * pow) % mod;
        powArr[i] = pow;

        pow = (pow * 31) % mod;
    }

    int start = 0, end = s2.size() - 1;

    vector<long> ans;

    while (end < s1.size())
    {
        long win = prefixHash[end];

        if (start > 0)
        {
            win = win - prefixHash[start - 1] + mod;
        }

        if (win == (desiredValue * powArr[start]) % mod)
        {
            ans.push_back(start + 1);
        }
        start++;
        end++;
    }

    if (ans.size() == 0)
    {
        cout << "Not Found" << endl;
        return;
    }

    for (int x : ans)
    {
        cout << x << " ";
    }

    return;
}

int main()
{

    return 0;
}