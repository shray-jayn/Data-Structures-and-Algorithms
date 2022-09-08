#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void minimumXorPairs(vector<int> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int minPair = INT_MAX;

    vector<string> result;

    for (int i = 0; i < n - 1; i++)
    {
        int XOR = (arr[i] ^ arr[i + 1]);

        if (XOR <= minPair)
        {
            result.push_back(arr[i] + " " + arr[i + 1]);
        }

        minPair = min(minPair, XOR);
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return;
}

int main()
{

    return 0;
}