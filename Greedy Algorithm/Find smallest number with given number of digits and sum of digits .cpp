#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string smallestNumber(int sum, int digits)
{
    if (9 * digits < sum)
    {
        return "-1";
    }

    string ans = "";

    for (int i = digits - 1; i >= 0; i--)
    {
        if (sum > 9)
        {
            sum -= 9;
            ans = "9" + ans;
        }

        else
        {
            if (i == 0)
            {
                ans = to_string(sum) + ans;
            }
            else
            {
                ans = to_string(sum - 1) + ans;
                i--;

                while (i > 0)
                {
                    ans = "0" + ans;
                    i--;
                }
                ans = "1" + ans;
                break;
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}