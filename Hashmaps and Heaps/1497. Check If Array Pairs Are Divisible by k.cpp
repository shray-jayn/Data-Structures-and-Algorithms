#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool canArrange(vector<int> &arr, int k)
{
    int n = arr.size();

    unordered_map<int, int> remainderMap;

    for (int i = 0; i < n; i++)
    {
        int rem = (arr[i] % k);

        remainderMap[rem]++;
    }

    for (int i = 0; i < n; i++)
    {
        int rem = (arr[i] % k);

        int freq = remainderMap[rem];

        if (rem == 0 and freq % 2 != 0)
        {
            return false;
        }

        else if (2 * rem == k and freq % 2 != 0)
        {
            return false;
        }

        else
        {
            int otherFreq = remainderMap[k - rem];

            if (otherFreq != freq)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{

    return 0;
}