#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int minimumLength(string s)
{
    int left = 0;
    int right = s.size() - 1;

    while (left < right && s.at(left) == s.at(right))
    {
        char x = s.at(left);

        // skip consecutive ones from both left and right end

        while (left < right && s.at(left) == x)
        {
            left++;
        }

        while (left <= right && s.at(right) == x)
        {
            right--;
        }
    }

    return right - left + 1;
}
