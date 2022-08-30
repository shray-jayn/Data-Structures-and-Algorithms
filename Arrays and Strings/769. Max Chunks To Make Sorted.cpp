#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maxChunksToSorted(vector<int> &arr)
{
    int n = arr.size();

    int maxEle = 0;
    int count = 0;

    for(int i = 0 ;i< n ;i++)
    {
        maxEle = max(maxEle, arr[i]);

        if(maxEle == i)
        {
            count++;
        }
    }

    return count ;
}

int main()
{

    return 0;
}