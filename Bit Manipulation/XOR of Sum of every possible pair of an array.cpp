#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int solution(vector<int> arr)
{
    int n = arr.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = ans ^ (2 * arr[i]);
    }

    return ans;
}

int main()
{

    return 0;
}