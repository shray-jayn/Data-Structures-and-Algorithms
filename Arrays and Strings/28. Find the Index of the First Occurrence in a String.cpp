#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int strStr(string haystack, string needle)
{
    int len = needle.length(), i = 0, j = 0;

    string temp;

    while (j < haystack.length())
    {
        temp += haystack[j];  // include

        if (j - i + 1 == len) // window size hit
        {
            if (temp == needle) // if equal return
                return i;
            temp.erase(temp.begin()); // slide the window
            i++;
        }
        
        j++;
    }
    return -1;
}

int main()
{
    // string a = "sadbutsad";
    // string b = "sad";

    // string a = "leetcode";
    // string b = "leeto";

    string a = "mississippi";
    string b = "issip";

    cout << strStr(a, b) << endl;

    return 0;
}