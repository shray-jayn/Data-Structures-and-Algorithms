#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }

        else
        {
            return false;
        }
    }

    return true;
}

bool validPalindrome(string s)
{
    int n = s.size();

    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }

        else
        {
            // skip from left or skip from right

            return isPalindrome(s, i + 1, j) or isPalindrome(s, i, j - 1);
        }
    }

    return true;
}

int main()
{

    return 0;
}