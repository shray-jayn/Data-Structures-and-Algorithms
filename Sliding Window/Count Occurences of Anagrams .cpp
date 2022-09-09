#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int search(string pat, string txt)
{

    unordered_map<char, int> umap;

    int i = 0;
    int j = 0;

    int k = pat.length();

    int ans = 0;
    int n = txt.size();

    for (int l = 0; l < k; l++)
    {
        umap[pat[l]]++;
    }

    int count = umap.size();

    while (j < n)
    {
        if (umap.find(txt[j]) != umap.end())
        {
            umap[txt[j]] -= 1;
            if (umap[txt[j]] == 0)
            {
                count -= 1;
            }
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (count == 0)
            {
                ans += 1;
                
            }
            if (umap.find(txt[i]) != umap.end())
            {
                umap[txt[i]] += 1;
                if (umap[txt[i]] == 1)
                {
                    count += 1;
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{

    return 0;
}