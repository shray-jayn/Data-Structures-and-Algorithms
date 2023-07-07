#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maxVowels(string s, int k)
{
    int n = s.size();

    int i = 0;
    int j = 0;

    int count = 0;

    int maxCount = INT_MIN;

    while (j < k)
    {
        if (s[j] == 'a' or s[j] == 'e' or s[j] == 'i' or s[j] == 'o' or s[j] == 'u')
        {
            count++;
        }
        j++;
    }

    // cout << i << " " << j << endl;

    // cout << count << endl;

    maxCount = max(maxCount, count);

    while (j < n)
    {
        // cout << i << " " << j << endl;

        if (s[j] == 'a' or s[j] == 'e' or s[j] == 'i' or s[j] == 'o' or s[j] == 'u')
        {
            count++;
        }
        if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
        {
            count--;
        }

        // cout << count << endl;

        maxCount = max(maxCount, count);
        i++;
        j++;
    }

    return maxCount;
}

int main()
{
    string s;
    cin >> s;

    int k;
    cin >> k;

    cout << maxVowels(s, k) << endl;

    return 0;
}