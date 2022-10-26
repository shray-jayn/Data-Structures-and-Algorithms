#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void reverseArr(vector<int> &arr, int l, int r)
{
    while (l < r)
    {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;

        l++;
        r--;
    }
}

vector<int> pancakeSort(vector<int> &arr)
{
    int n = arr.size();

    vector<int> ans;

    for (int i = n - 1; i >= 0; i--)
    {
        int maxIdx = i;

        for (int j = i - 1; j >= 0; j--) // look for greater element in left part
        {
            if (arr[maxIdx] < arr[j])
            {
                maxIdx = j; // update greater element
            }
        }

        if (maxIdx != i) // only if greater element is found
        {
            reverseArr(arr, 0, maxIdx); // first flip
            ans.push_back(maxIdx + 1);

            reverseArr(arr, 0, i); // second flip
            ans.push_back(i + 1);
        }
    }

    return ans;
}

int main()
{

    return 0;
}