#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool static myCmp(string &a, string &b)
{
    return a + b > b + a; // 330>303
}

string largestNumber(vector<int> &nums)
{
    int len = nums.size();

    vector<string> vc;

    for (int num : nums)
    {
        vc.push_back(to_string(num));
    }

    sort(vc.begin(), vc.end(), myCmp);

    string res = "";

    for (string str : vc)
    {
        res += str;
    }

    if (res[0] == '0')
    {
        return "0"; // if we get multiple zeroes}
    }
        
    return res;
}

int main()
{

    return 0;
}