#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string multiply(string num1, string num2)
{
    if (num1 == "0" or num2 == "0")
    {
        return "0";
    }

    int l1 = num1.size();
    int l2 = num2.size();

    vector<int> res(l1 + l2, 0);

    int n = l1 + l2;

    int i = l2 - 1;
    int powerFactor = 0;

    while (i >= 0)
    {
        int iVal = num2[i] - '0';
        i--;

        int j = l1 - 1;
        int k = n - 1 - powerFactor;

        int carry = 0;

        while (j >= 0 or carry != 0)
        {
            int jVal = j >= 0 ? num1[j] - '0' : 0;
            j--;

            int product = iVal * jVal + carry + res[k];

            res[k] = product % 10;
            carry = product / 10;
            k--;
        }

        powerFactor++;
    }

    // Management of leading zeros using general method;

    string str = "";
    bool flag = false;

    for (auto it : res)
    {
        int val = it;

        if (val == 0 and flag == false)
        {
            // leading zeros hai yaha
            continue;
        }
        else
        {
            flag = true;
            str.push_back(val + '0');
        }
    }

    return str;
}

int main()
{

    return 0;
}