#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void computeLpsArr(vector<int> &lps, string &pat, int &m)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0 as prefix == suffix == only element

    // loop to cal. lps[1] -> lps[m-1];

    int i = 1;

    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }

        else
        { // if no equal element found

            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.

            if (len != 0)
            {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }

            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string &txt, string &pat)
{
    int m = pat.size();
    int n = txt.size();

    // create lps[] to hold longest prefix and suffix value for pattern ;

    vector<int> lps(m);

    computeLpsArr(lps, pat, m);

    int i = 0; // for text
    int j = 0; // for pat

    while (i < n)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == m)
        {
            cout << "Found Pattern at index " << i - j << endl;
            j = lps[j - 1];
        }

        else if (i < n && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway

            if (j != 0)
            {
                j = lps[j - 1];
            }
            
            else
            {
                i = i + 1;
            }
        }
    }
}

int main()
{
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";

    return 0;
}