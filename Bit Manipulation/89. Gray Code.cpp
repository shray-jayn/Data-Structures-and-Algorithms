#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> grayCode(int n)
{

    if (n == 1)
    {
        return {0, 1};
    }

    vector<int> rres = grayCode(n - 1);

    vector<int> mres;

    for (int i = 0; i < rres.size(); i++)
    {
        string rstr = to_string(rres[i]);
        rstr = "0" + rstr;

        mres.push_back(stoi(rstr));
    }

    for (int i = rres.size() - 1; i >= 0; i--)
    {
        string rstr = to_string(rres[i]);
        rstr = "1" + rstr;

        mres.push_back(stoi(rstr));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}