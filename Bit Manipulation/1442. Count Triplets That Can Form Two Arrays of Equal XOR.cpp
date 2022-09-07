#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int countTriplets(vector<int> &arr)
{
    int n = arr.size();

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int XOR = arr[i];

        for (int k = i + 1; k < n; k++)
        {
            XOR = XOR ^ arr[k];

            if (XOR == 0)
            {
                count += (k - i);
            }
        }
    }

    return count;
}

int main()
{

    return 0;
}