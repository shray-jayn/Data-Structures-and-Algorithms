#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findShortestSubArray(vector<int> &arr)
{
    int n = arr.size();

    unordered_map<int, int> freq;
    unordered_map<int, int> startIdx;

    int highestFreq = 0;
    int startPoint = 0;
    int endPoint = 0;
    int len = endPoint - startPoint + 1;

    for (int i = 0; i < n; i++)
    {
        if (freq.find(arr[i]) != freq.end())
        {
            freq[arr[i]]++;
        }
        else
        {
            freq[arr[i]]++;
            startIdx[arr[i]] = i;
        }

        if (highestFreq < freq[arr[i]])
        {
            highestFreq = freq[arr[i]];
            startPoint = startIdx[arr[i]];
            endPoint = i;
            len = endPoint - startPoint + 1;
        }
        else if (highestFreq == freq[arr[i]])
        {
            int challengeLen = i - startIdx[arr[i]] + 1;
            if (challengeLen < len)
            {
                highestFreq = freq[arr[i]];
                startPoint = startIdx[arr[i]];
                endPoint = i;
                len = endPoint - startPoint + 1;
            }
        }
    }

    return len;
}

int main()
{

    return 0;
}